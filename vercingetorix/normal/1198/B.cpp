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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    readv(a,n);
    int q;
    read(q);
    vector<pair<int, pi>> ev;
    forn(aaf,0,q) {
        int tp;
        scanf("%d", &tp);
        int p,x;
        if(tp == 1) {
            scanf("%d %d", &p, &x);
            p--;
            ev.pb(mp(tp, mp(p,x)));
        }
        else {
            scanf("%d", &x);
            ev.pb(mp(tp, mp(x,x)));
        }
    }
    reverse(all(ev));
    vi taken(n,0);
    int curmin = 0;
    for(auto v : ev) {
        if(v.first == 2) curmin = max(curmin, v.second.first);
        else {
            if(taken[v.second.first]) continue;
            else {
                int u = v.second.first;
                taken[v.second.first] = 1;
                a[u] = max(v.second.second, curmin);
            }
        }
    }
    forn(i,0,n) if(taken[i] == 0) a[i] = max(a[i], curmin);
    forn(i,0,n) printf("%d ", a[i]);
    
}