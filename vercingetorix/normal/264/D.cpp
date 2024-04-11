#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
int getn(char a, char b) {
    int ret = 0;
    if(b=='G') ret++;
    else if(b=='B') ret+=2;
    if(a=='G') ret+=3;
    else if(a=='B') ret+=6;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s,t;
    getline(cin, s);
    getline(cin, t);
    int n = s.size();
    int m = t.size();
    ll ans = 0;
    vi l(n+1,m), r(n+1,m-1);
    int ps = 0;
    int pt = 0;
    while(pt < m && ps < n) {
        if(s[ps] == t[pt]) {
            r[ps] = pt;
            ps++;
        }
        pt++;
        if(pt == n) r[ps] = m-1;
    }
    ps = 0;
    pt = 0;
    l[0] = 0;
    while(pt < m && ps < n) {
        if(s[ps] == t[pt]) {
            pt++;
        }
        ps++;
        l[ps] = pt;
    }
    vi cnt(9,0);
    int curl = 0;
    int curr = 0;
    forn(i,0,n) {
        while(curr < r[i]) {
            if(curr != m-1) cnt[getn(t[curr], t[curr+1])] ++;
            curr++;
        }
        while(curl < l[i]) {
            if(curl != m-1) cnt[getn(t[curl], t[curl+1])] --;
            curl++;
        }
        ans += curr-curl+1;
        if(i>0 && s[i]!=s[i-1]) {
            int val = getn(s[i], s[i-1]);
            ans -= cnt[val];
        }
    }
//    forn(i,0,n) ans += r[i]-l[i]+1;
    cout<<ans;
    
}