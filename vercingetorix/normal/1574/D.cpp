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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int n,m;
vi a[10];
vi ans;
int best = 0;

int val = 0;
int curfall = 1;
vi cand;
set<vi> ban;

//void go(int i) {
//    if(i == n) {
//        if(val > best)
//            if(ban.find(cand) == ban.end()) {
//                ans = cand;
//                best = val;
//            }
//        return;
//    }
//    forn(tk,0,a[i].size()) {
//        if(curfall * (tk+1) > m+1) break;
//        curfall *= (tk+1);
//        val += a[i][tk];
//        cand.pb(tk);
//        go(i+1);
//        cand.pop_back();
//        val -= a[i][tk];
//        curfall /= (tk+1);
//    }
//}

void go(const vi & x) {
    val = 0;
    forn(i,0,n) val += a[i][x[i]];
    if(val > best)
        if(ban.find(x) == ban.end()) {
            best = val;
            ans = x;
        }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,n) {
        int k;
        scanf("%d", &k);
        a[i].resize(k);
        forn(j,0,k) scanf("%d", &a[i][j]);
        reverse(all(a[i]));
    }
    scanf("%d", &m);
    forn(i,0,m) {
        readv(x,n);
        forn(i,0,n) x[i] = (int)a[i].size() - x[i];
        ban.insert(x);
    }
    go(vi(n,0));
    for(auto x : ban) {
        forn(i,0,n) {
            if(x[i] + 1 < a[i].size()) {
                x[i]++;
                go(x);
                x[i]--;
            }
        }
    }
//    go(0);
    forn(i,0,n) printf("%d ", (int)a[i].size() - ans[i]);
}