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
    char c[300500];
    while(t--) {
        int n;
        scanf("%d\n", &n);
        scanf("%s", c);
        int cur = 0;
        vi l(n), r(n);
        forn(i,0,n) {
            if(i == 0 || c[i] == c[i-1]) cur = 1;
            else cur++;
            l[i] = cur;
        }
        for(int i = n-1; i>=0; i--){
            if(i == n-1 || c[i] == c[i+1]) cur = 1;
            else cur++;
            r[i] = cur;
        }
        forn(i,0,n+1) {
            int ans = 1;
            if(i>0 && c[i-1] == 'L') ans += l[i-1];
            if(i<n && c[i] == 'R') ans += r[i];
            printf("%d ", ans);
        }
        printf("\n");
    }
    
}