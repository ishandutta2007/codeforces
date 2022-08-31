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

int d[76][1100000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi d2(1,1);
    forn(i,0,23) d2.pb(d2.back()*2);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi a;
    for(auto c:s) a.pb(c-'0');
//    d[0][0] = 1;
    ll ans = 0;
    forn(i,0,n+1) {
        int cur = 0;
        forn(k,1,21) {
            ans += d[i][d2[k]-1];
        }
        ans %= mod;
        d[i][0] = (d[i][0]+1)%mod;
        forn(j,i,n) {
            cur = cur*2 + a[j];
            if(cur > 20) break;
            if(cur==0) continue;
            int bit = d2[cur-1];
            forn(mask,0,d2[20]) {
                d[j+1][mask|bit] = (d[j+1][mask|bit] + d[i][mask]) % mod;
            }
        }
    }
    cout<<ans;
    
}