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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    char c[100000];
    while(t--) {
        int n;
        int u,r,d,l;
        scanf("%d %d %d %d %d", &n, &u, &r, &d, &l);
        if(u+d - 2*n + 4 > r+l) printf("NO\n");
        else if(r+l-2*n+4>u+d) printf("NO\n");
        else if((u == n||d==n) && r*l == 0) printf("NO\n");
        else if((l == n||r==n) && u*d == 0) printf("NO\n");
        else if(r+l == 0 && max(u,d) >=n-1) printf("NO\n");
        else if(u+d == 0 && max(r,l) >=n-1) printf("NO\n");
        else if(d+u==2*n && min(r,l) <= 1) printf("NO\n");
        else if(r+l==2*n && min(u,d) <= 1) printf("NO\n");
        else printf("YES\n");
        
        
        
    }
    
    
}