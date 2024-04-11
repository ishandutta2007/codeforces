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
const int A = 5005;
int d[A][A];
int nd[A][A];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char c[300500];
    while(t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", c);
        string s(c);
        s.pb(30);
        forn(i,0,n) forn(j,0,n) d[i][j] = 0;
        for(int i = n; i>=0;i--) {
            for(int j=n; j>=0;j--) {
                if(i==j) continue;
                if(s[i]!=s[j]) nd[i][j] = 0;
                else nd[i][j] = nd[i+1][j+1] + 1;
            }
        }
        forn(st,0,n) {
            d[st][0] = 1;
            forn(p,0,st) {
                int add = nd[st][p];
                if(s[st+add] < s[p+add]) continue;
                d[st][add] = max(d[st][add], d[p][n-p-1]+1);
            }
            forn(i,1,n-st) d[st][i] = max(d[st][i],d[st][i-1]+1);
        }
        int ans = 0;
        forn(i,0,n) forn(j,0,n) ans= max(ans,d[i][j]);
        printf("%d\n", ans);
       
    }
    
    
}