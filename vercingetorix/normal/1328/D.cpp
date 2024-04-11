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
    read(t);
    char c[200500];
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        int dif = 0;
        int ind = -1;
        forn(i,0,n) {
            int j = (i+1)%n;
            if(a[i] != a[j]) dif = 1;
            if(a[i] == a[j]) ind = j;
        }
        if(dif == 0) {
            printf("1\n");
            forn(i,0,n) printf("1 ");
            printf("\n");
            continue;
        }
        else if(n%2==0 || ind != -1) {
            if(ind == -1) ind = 0;
            printf("2\n");
            vi ans(n);
            forn(i,0,n) ans[(ind + i)%n] = 1+i%2;
            forn(i,0,n) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
        else {
            printf("3\n");
            printf("3 ");
            forn(i,1,n) printf("%d ", 1+i%2);
            printf("\n");
        }
        
    }
    
    
}