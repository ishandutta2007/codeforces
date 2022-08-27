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
    int n,m;
    scanf("%d %d", &n, &m);
    vvi a(n, vi(m+2,0));
    forn(i,0,n) {
        a[i][0] = 0;
        a[i][m+1] = 0;
        int k;
        scanf("%d", &k);
        forn(j,1,k+1) {
            int l,r;
            scanf("%d %d", &l, &r);
//            l--;
//            r--;
            forn(u,l,r+1) a[i][u] = j;
        }
    }
    ll ans = 0;
//    forn(i,0,n) {
//        forn(j,0,m+2) cout<<a[i][j];cout<<endl;
//    }
    vvi best(m+2, vi(m+2,0));
    forn(st,2,m+2) {
        forn(l,0,m+2-st) {
            int r = l + st;
            
            forn(m,l+1,r) {
                int cnt = 0;
                forn(i,0,n) if(a[i][l] != a[i][m] && a[i][r] != a[i][m]) cnt++;
                best[l][r] = max(best[l][m] + best[m][r] + cnt*cnt, best[l][r]);
            }
//            cout<<l<<' '<<r<<' '<<best[l][r]<<endl;
        }
    }
    cout<<best[0][m+1];
}