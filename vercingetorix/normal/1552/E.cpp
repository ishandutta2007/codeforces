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
    scanf("%d %d", &n, &k);
    readv(a, n*k);
    vvi col(n);
    forn(i,0,n*k) a[i]--;
    forn(i,0,n*k) col[a[i]].pb(i);
    vpi ans(n);
    for(int l = 0; l < n; l+=(k-1)) {
        int t = min(l+k-1, n)-l;
        vi taken(t, 0);
        int cur = 1;
        forn(i,0,t) {
            int ind = -1;
            forn(j,0,t) {
                if(taken[j]) continue;
                if(ind == -1 || col[l+j][cur] < col[l+ind][cur]) ind = j;
            }
            ans[l+ind] = mp(col[l+ind][cur-1], col[l+ind][cur]);
            taken[ind] = 1;
            cur++;
        }
    }
    forn(i,0,n) printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    
}