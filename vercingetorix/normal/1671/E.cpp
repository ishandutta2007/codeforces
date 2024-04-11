#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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

const long long mod = 998244353;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int n;
string s;

int comp(int s1, int s2, int l) {
    forn(i,0,l) {
        if(s[s1+i] < s[s2+i]) return -1;
        else if(s[s1+i] > s[s2+i]) return 1;
    }
    return 0;
}

ll ans = 1;
string go(int v) {
    if(v*2 >= (1<<n)) return string(1, s[v-1]);
    else {
        string s1 = go(v*2);
        string s2 = go(v*2+1);
        if(s1!=s2) ans = ans*2%mod;
        if(s2 < s1) swap(s1,s2);
        return string(1, s[v-1]) + s1 + s2;
    }
}
//void go(int v, int tl, int tr) {
//    if(tl != tr) {
//        int tm = (tl+tr)/2;
//        go(v*2, tl, tm);
//        go(v*2+1, tm+1, tr);
//        int res = comp(tl, tm+1, tm+1-tl);
//        if(res != 0) ans = ans*2%mod;
//        if(res == 1) {
//            forn(i,0,tm+1-tl) swap(s[tl+i], s[tm+1+i]);
//        }
//    }
//}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin >> n >> s;
    go(1);
//    go(1,0,(1<<n)-1);
    cout<<ans;
}