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
    int n,k;
    scanf("%d %d\n", &n, &k);
    char c[200500];
    scanf("%s", c);
    vi last(k, n);
    vvi nx(k, vi(n,0));
    for(int i = n-1; i>=0; i--) {
        if(c[i] != '?') last[c[i]-'a'] = i;
        forn(j,0,k) nx[j][i] = last[j];
    }
    int l = 0;
    int r = n+1;
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back()*2);
    while(r-l > 1) {
        int m = (r+l)/2;
        vvi nxcan(k, vi(n, n));
        for(int i = n-1; i>=0; i--) {
            vi force;
            forn(j,0,k) if(nx[j][i] - i < m)
                force.pb(j);
            if(force.size() == 0) {
                forn(j,0,k) nxcan[j][i] = i;
            }
            else if(force.size() == 1) {
                if(i<n-1) forn(j,0,k) nxcan[j][i] = nxcan[j][i+1];
                nxcan[force[0]][i] = i;
            }
            else if(i<n-1) {
                forn(j,0,k) nxcan[j][i] = nxcan[j][i+1];
            }
        }
        vi minr(d2[k], n);
        minr[0] = -1;
        forn(mask, 1, d2[k]) {
            forn(bit,0,k) if(mask&d2[bit]) {
                if(minr[mask^d2[bit]] < n-1) minr[mask] = min(minr[mask], nxcan[bit][minr[mask^d2[bit]] + 1] + m -1);
            }
        }
        if(minr[d2[k]-1] < n) l = m;
        else r = m;
    }
    cout<<l;
    
    
}