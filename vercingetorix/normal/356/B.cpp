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
long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
    scanf("%lld %lld\n", &n, &m);
    string s,t;
    getline(cin, s);
    getline(cin, t);
    ll sl = s.size();
    ll tl = t.size();
    ll d = gcd(sl, tl);
    ll nok = sl*tl/d;
    ll rd = sl*n;
    ll kr = rd/nok;
    ll ans = 0;
    forn(i,0,d) {
        vll a(26,0);
        vll b(26,0);
        ll snum = sl/d;
        ll tnum = tl/d;
        forn(j,0,snum) a[s[i+j*d] - 'a']++;
        forn(j,0,tnum) b[t[i+j*d] - 'a']++;
        forn(i,0,26) {
            ans += a[i] * (tnum - b[i]);
        }
    }
    cout<<ans*kr;
    
    
}