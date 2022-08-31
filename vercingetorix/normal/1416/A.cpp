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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(afa,0,t) {
        int n;
        read(n);
        readv(a, n);
        map<int, vi> b;
        forn(i,0,n) b[a[i]].pb(i);
//        pi ans = mp(n, a[0]);
        vi ans(n+1, n+1);
        for(auto x : b) {
            auto u = x.second;
            int m = x.first;
            int k = u[0] + 1;
            k = max(k, n-u.back());
            forn(i,0,u.size() - 1) {
                k = max(k, u[i+1]-u[i]);
            }
            if (ans[k] == -1) ans[k] = m;
            else ans[k] = min(ans[k], m);
//            ans = min(ans, mp(k, m));
        }
        forn(i,0,n) ans[i+1] = min(ans[i+1], ans[i]);
        forn(i,0,n+1) if (ans[i]==n+1) ans[i] = -1;
        int cur = -1;
        forn(i,0,n) {
//            if(ans.first <= i+1) printf("%d", ans.second);
//            if(cur == -1) cur = ans[i+1];
//            else cur = min(cur, ans[i+1]);
            printf("%d", ans[i+1]);
            if(i<n-1) printf(" ");
        }
        printf("\n");
    }
    
    
}