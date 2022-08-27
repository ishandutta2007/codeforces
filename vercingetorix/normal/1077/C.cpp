#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
//#include <queue>
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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(c, n);
    vector<int> res;
    long long s = 0;
    forn(i, 0, n) s += c[i];
    vpll a, b;
    forn(i,0,n) a.pb(mp(c[i], i)), b.pb(mp(s-2*c[i], -i));
    sort(all(a));
    sort(all(b));
    int p=0,q=0;
    while(q < n) {
        if(p == n || b[p].first > a[q].first) q++;
        else if(b[p].first < a[q].first) p++;
        else {
            if(a[q].second != -b[p].second) {
                res.pb(a[q].second);
                q++;
            }
            else p++;
        }
    }
    printf("%d\n", res.size());
    for(auto x : res) printf("%d ", x+1);
}