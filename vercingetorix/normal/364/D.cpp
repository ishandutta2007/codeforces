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
#include <ctime>
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

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

set<ll> was;
vll por;
ll ans = 1;
int n;
vll a;
void go(ll cur) {
    if(clock() >= CLOCKS_PER_SEC*3) return;
    if(was.find(cur)!=was.end()) return;
    was.insert(cur);
    
    int cnt = 0;
    forn(i,0,n) {
        if(a[i] % cur == 0) cnt++;
    }
    if(cnt*2>=n) ans = max(ans,cur);
    for(auto x : por) {
        if(clock() >= CLOCKS_PER_SEC*3) break;
        if(cur*x <= 1000000000000ll) go(x*cur);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 1000000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    
    scanf("%d", &n);
    
    a.resize(n);
    forn(i,0,n) {
        scanf("%lld", &a[i]);
    }
    
    for(auto pr:p) {
        if(pr>100) break;
        
        int dp = pr;
        bool cleanse = false;
        while(dp<100) {
            int cnt = 0;
            forn(i,0,n) {
                if(a[i]%dp == 0) cnt++;
            }
            if(cnt*2 < n) {
                cleanse = true;
                break;
            }
            dp *= pr;
        }
        if(cleanse) {
            dp/=pr;
            forn(i,0,n) {
                if(a[i] % dp !=0) continue;
                a[i] /= dp;
                while(a[i] % pr == 0) a[i] /= pr;
                a[i] *= dp;
            }
        }
    }
    
    
    std::random_device rd;
    std::mt19937_64 e2(rd());
    int k = 20;
    vll cand;
    vi tested(1000001,0);
    vll tg;
    forn(i,0,k) {
        if(clock() >= CLOCKS_PER_SEC*3) break;
        ll cur = a[e2()%n];
        map<ll, int> cnt;
        forn(j,0,n) cnt[gcd(cur, a[j])]++;
        vll div(1,1);
        for(auto pr : p) {
            if(cur % pr == 0) {
//                if(clock() >= CLOCKS_PER_SEC*3) break;
                int d = 1;
                cur/=pr;
                while(cur%pr==0) {
                    d++;
                    cur/=pr;
                }
                tg.pb(pr);
                int num = div.size();
                ll dp = pr;
                forn(i,0,d) {
                    forn(i,0,num) div.pb(div[i] * dp);
                    dp*=pr;
                }
            }
        }
//        if(clock() >= CLOCKS_PER_SEC*3) break;
        if(cur > 1) {
            int num = div.size();
            forn(i,0,num) div.pb(div[i] * cur);
            cur = 1;
        }
        sort(all(div));
        reverse(all(div));
//        int lol = 1;
        for(auto x : div) {
            if(x <= ans) continue;
            if(x<=1000000 && tested[x]) continue;
            if(x<=1000000) tested[x] = 1;
            int num = 0;
            for(auto u : cnt) {
                if(u.first % x == 0) num+=u.second;
            }
            if(2*num>=n) ans = x;
//            lol++;
//            if(lol%100==0) {
//                if(clock() >= CLOCKS_PER_SEC*3) break;
//            }
//            int cnt = 0 ;
//            forn(i,0,100) {
//                if(a[rand()%n] % x == 0) cnt++;
//            }
//            if(cnt<35) continue;
//            cnt = 0;
//            forn(i,0,n) {
//                if(a[i] % x == 0) cnt++;
//            }
//            if(cnt*2>=n) ans = x;
        }
    }
//    sort(all(tg));
//    forn(i,0,tg.size()) {
//        if(i == 0 || tg[i] != tg[i-1]) por.pb(tg[i]);
//    }
//    go(1);
    
    cout<<ans;
}