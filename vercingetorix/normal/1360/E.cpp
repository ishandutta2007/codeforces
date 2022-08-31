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
    int t;
    read(t);
    while(t--) {
        int n,k;
        scanf("%d\n", &n);
        vs a;
        char c[100500];
        forn(i,0,n) {
            scanf("%s", c);
            a.pb(string(c));
        }
        vvi vis(n, vi(n, 0));
        vpi q;
        forn(i,0,n) q.pb(mp(n,i));
        forn(i,0,n) q.pb(mp(i,n));
        while(!q.empty()) {
            int i = q.back().first;
            int j = q.back().second;
            q.pop_back();
            forn(id,0,2) {
                int i2 = i - id;
                int j2 = j - (1 - id);
                if(i2>=0 && j2>=0 && i2<n && j2<n &&vis[i2][j2]==0 &&a[i2][j2] == '1') {
                    vis[i2][j2] = 1;
                    q.pb(mp(i2,j2));
                }
            }
        }
        string ans = "YES\n";
        forn(i,0,n) forn(j,0,n) if(vis[i][j] == 0 && a[i][j] == '1') ans = "NO\n";
        printf("%s", ans.c_str());
    }
    
}