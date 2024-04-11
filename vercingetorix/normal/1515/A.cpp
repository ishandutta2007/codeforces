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
    forn(ifa,0,t) {
        int n, x;
        scanf("%d %d", &n, &x);
        readv(a,n);
        int same= 1;
        forn(i,0,n) if(a[i] != a[n-1]) {
            swap(a[i], a[n-2]);
            same = 0;
            break;
        }
        if(same) {
            if(x%a[0] == 0 && x<=a[0]*n) printf("NO\n");
            else {
                printf("YES\n");
                forn(i,0,n) printf("%d ", a[0]);
                printf("\n");
            }
            continue;
        }
        int sum = 0;
        forn(i,0,n) {
            sum+=a[i];
        }
        if(sum==x) {
            printf("NO\n");
            continue;
        }
        sum = 0;
        forn(i,0,n) {
            sum+=a[i];
            if(sum == x) {
                if(a[i+1] == a[i]) swap(a[i+1], a[n-1]);
                if(a[i+1] == a[i]) swap(a[i+1], a[n-2]);
                swap(a[i], a[i+1]);
            }
        }
        printf("YES\n");
        for(auto xx : a) printf("%d ", xx);
        printf("\n");
        
    }
    
    
}