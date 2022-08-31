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
    scanf("%d\n", &t);
    char c1[501], c2[2000];
    while(t--) {
        scanf("%s", c1);
        scanf("%s", c2);
        string s(c1);
        string t(c2);
        int n = s.size();
        int m = t.size();
        vvi d(n+1, vi(m+1, 0));
        for(int i = n-1; i>=0; i--) for(int j = m-1; j>=0; j--) {
            if(s[i] == t[j]) d[i][j] = d[i+1][j+1] + 1;
        }
        string tr = t;
        reverse(all(tr));
        vvi dr(n+1, vi(m+1, 0));
        for(int i = n-1; i>=0; i--) for(int j = m-1; j>=0; j--) {
            if(s[i] == tr[j]) dr[i][j] = dr[i+1][j+1] + 1;
        }
        int can = 0;
        forn(s,0,n) forn(f,s,n) {
            if(d[s][0] >= f-s+1) {
                int l = f-s+1;
                int r = m-l;
                if(f>=r && dr[f-r][0] >= r) {
                    can = 1;
                }
            }
        }
        if(can) printf("YES\n");
        else printf("NO\n");
    }
    
}