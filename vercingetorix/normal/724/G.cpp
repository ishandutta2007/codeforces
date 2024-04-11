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
int n,m;
vector<vector<pll>> nb;
vll num;
vll cl;
vi comp;
void dfs(int v, int p) {
    comp.pb(v);
    for(auto x : nb[v]) {
        if(x.first == p) continue;
        if(num[x.first] != -1) {
            cl.pb(num[x.first]^num[v]^x.second);
        }
        else {
            num[x.first] = num[v] ^ x.second;
            dfs(x.first, v);
        }
    }
}

vll d2(1,1);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvll cnk(100, vll(100, 0));
    forn(i,0,100) cnk[i][0] = 1;
    forn(i,1,100) {
        forn(j,1,i+1) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    
    scanf("%d %d", &n, &m);
    
    forn(i,0,60) d2.pb(d2.back()*2);
    num.resize(n);
    forn(i,0,n) num[i] = -1;
    nb.resize(n);

    for(int i=0;i<m;i++){
        int u,v;
        ll t;
        scanf("%d %d %lld", &u, &v, &t);
        u--; v--;
        nb[u].push_back(mp(v, t));
        nb[v].push_back(mp(u, t));
    }
    
    ll ans = 0;
    forn(s,0,n) {
        if(num[s] >= 0) continue;
        comp.clear();
        cl.clear();
        num[s] = 0;
        dfs(s,-1);
        
        int l = cl.size();
        int bit = 60;
        vi imp;
        int cur = 0;
        while(bit>=0) {
            bool f = false;
            forn(i,cur,l) {
                if(cl[i] & d2[bit]) {
                    swap(cl[i], cl[cur]);
                    f=true;
                    break;
                }
            }
            if(f) {
                forn(i,cur+1,l) {
                    if(cl[i] & d2[bit]) {
                        cl[i] = cl[i] ^ cl[cur];
                    }
                }
                cur++;
            }
            bit--;
        }
        vll basis;
        forn(i,0,cur) basis.pb(cl[i]);
        l = cur;
        
        
        forn(bit,0,61) {
            ll a0 = 0;
            ll a1 = 0;
            ll b0 = 0;
            ll b1 = 0;
            for(auto i : comp) {
                if(num[i] & d2[bit]) a1++;
                else a0++;
            }
            forn(i,0,l) {
                if(basis[i]&d2[bit]) b1++;
                else b0++;
            }
            ll n0 = ((a0 * (a0-1))/2) % mod + ((a1 * (a1-1))/2) % mod;
            n0 = n0 % mod;
            ll n1 = (a0*a1) % mod;
            ll odd = 0;
            ll ev = 0;
            for(int i = 0; i <= b1; i += 2) ev = (ev + (d2[b0]%mod)*cnk[b1][i])%mod;
            for(int i = 1; i <= b1; i += 2) odd = (odd + (d2[b0]%mod)*cnk[b1][i])%mod;
            ll cnt = (n0*odd + n1*ev)%mod;
            ans =  (ans + (d2[bit]%mod)* cnt)%mod;
            
        }
        
    }
    cout<<ans;

}