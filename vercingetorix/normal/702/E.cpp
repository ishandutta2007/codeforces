#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

vi to,used;
vvi par;
vll s,m;
vll w;

int cnt;
void dfscnt(int v) {
    cnt++;
    for(auto u:par[v]) {
        if(!used[u]) {
            dfscnt(u);
        }
    }
}

ll cursum;
multiset<ll> nums;

void dfsmuch(int v, const deque<int> & ord, int en) {
    used[v] = 1;
    s[v] = cursum;
    m[v] = *(nums.begin());
    for(auto u:par[v]) {
        if(!used[u]) {
            nums.insert(w[u]);
            cursum += w[u];
            int en2 = en - 1;
            if(en==0) en2 = ord.size() - 1;
            cursum-=w[ord[en2]];
            dfsmuch(u, ord, en2);
            cursum+=w[ord[en2]];
            cursum -= w[u];
            nums.erase(nums.find(w[u]));
        }
    }
}

deque<ll> wg;
void dfsdeque(int v) {
    used[v] = 1;
    s[v] = cursum;
    m[v] = *(nums.begin());
    for(auto u:par[v]) {
        if(!used[u]) {
            wg.push_front(w[u]);
            ll rem = wg.back();
            nums.erase(nums.find(rem));
            wg.pop_back();
            nums.insert(w[u]);
            cursum += w[u];
            cursum-=rem;
            dfsdeque(u);
            cursum -= w[u];
            cursum += rem;
            nums.erase(nums.find(w[u]));
            nums.insert(rem);
            wg.pop_front();
            wg.pb(rem);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    to.resize(n);
    par.resize(n);
    w.resize(n);
    forn(i,0,n) {
        scanf("%d", &to[i]);
        par[to[i]].pb(i);
    }
    forn(i,0,n) scanf("%lld", &w[i]);
    
    vvll ss(35, vll(n,0));
    vvll mm(35, vll(n,0));
    vvi son(35, vi(n,0));
    forn(i,0,n) {
        son[0][i] = to[i];
        ss[0][i] = w[i];
        mm[0][i] = w[i];
    }
    vll d2(1,1);
    forn(p,1,35) {
        d2.pb(d2.back()*2);
        forn(i,0,n) {
            int step = son[p-1][i];
            son[p][i] = son[p-1][step];
            mm[p][i] = min(mm[p-1][i], mm[p-1][step]);
            ss[p][i] = ss[p-1][i] + ss[p-1][step];
        }
    }
    vi proc;
    for(int i = 34; i>=0; i--) {
        if(k>=d2[i]) {
            k-=d2[i];
            proc.pb(i);
        }
    }
    s.resize(n);
    m.resize(n);
    forn(i,0,n) {
        int cur = i;
        ll sss = 0;
        ll www = 1000000000000;
        for(auto x : proc) {
            sss += ss[x][cur];
            www = min(www, mm[x][cur]);
            cur = son[x][cur];
        }
        s[i]=sss;
        m[i]=www;
    }
    
    forn(i,0,n) printf("%lld %lld\n", s[i], m[i]);
    
    return 0;
    
    used = vi(n,0);
    
  
    forn(i,0,n) {
        if(!used[i]) {
            deque<int> ord;
            int cur = i;
            while (!used[cur]) {
                used[cur] = 1;
                ord.pb(cur);
                cur = to[cur];
            }
            while(ord[0] != cur) {
                used[ord[0]] = 0;
                ord.pop_front();
            }
            int l = ord.size();
            int st = 0;
            int en = (k)%l;
            ll loops = k/(ll)l;
            ll sum = 0;
            forn(j,0,l) {
                sum += loops*w[ord[j]];
            }
            forn(j,0,en) {
                sum += w[ord[j]];
            }
            forn(j,0,l) {
                s[ord[j]] = sum;
                sum -= w[ord[j]];
                sum += w[ord[en]];
                en++;
                if(en==l) en=0;
            }
            cnt = 0;
            for(auto x : ord) dfscnt(x);
            if(k>=cnt) {
                nums.clear();
                ll minc = 1000000000;
                for(auto x:ord) minc = min(minc, w[x]);
                nums.insert(minc);
                forn(st,0,l) {
                    cursum = s[ord[st]];
                    dfsmuch(ord[st], ord, (int)((ll)st+k)%l);
                }
            }
            else {
                st = 0;
                wg.clear();
                nums.clear();
                cursum = 0;
                forn(j,0,k) {
                    int ind = ord[j%l];
                    wg.pb(w[ind]);
                    nums.insert(w[ind]);
                    cursum+=w[ind];
                }
                int en = k%l;
                forn(j,0,l) {
                    dfsdeque(ord[j]);
                    cursum-=w[ord[j]];
                    wg.pop_front();
                    nums.erase(nums.find(w[ord[j]]));
                    
                    wg.pb(w[ord[en]]);
                    cursum+=w[ord[en]];
                    nums.insert(w[ord[en]]);
                    en++;
                    if(en==l) en=0;
                }
            }
            
        }
    }
    
    
    
    
}