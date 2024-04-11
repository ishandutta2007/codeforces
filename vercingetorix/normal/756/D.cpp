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

//int d[26][5001];
//int last[26][5001];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
//    string s;
    char c[5200];
//    getline(cin, s);
    scanf("%s", c);
    string s(c);
    int pt = 0;
    int cnt = 0;
    vi t;
    forn(i,0,n) if(i==0 || s[i] != s[i-1]) {
        cnt++;
        t.pb(int(s[i]-'a'));
    }
    vvi d(26, vi(n+1,0));
    vvi last(26, vi(n+1,0));
    forn(i,0,n+1) last[t[0]][i] = mod-1;
    forn(i,0,n+1) {
        d[t[0]][i] = 1;
    }
    forn(sym,1,cnt) {
        int cur = t[sym];
        vi cum(26, 0);
        forn(i,1,n+1) {
            ll cand = 1;
            forn(j,0,26) {
                if(j!=cur) {
                    cand += cum[j];
                    cum[j] += d[j][i];
                    if(cum[j] >= mod) cum[j]-=mod;
                }
            }
            cand%=mod;
            d[cur][i] += cand+last[cur][i];
//            d[cur][i] %= mod;
            if(d[cur][i] >= mod) d[cur][i] -= mod;
            last[cur][i]= mod-d[cur][i];
            cum[cur] += d[cur][i];
            cum[cur] %= mod;
        }
    }
    ll ans = 0;
    forn(i,0,26) ans += d[i][n];
    cout<<ans%mod;
    
    
}