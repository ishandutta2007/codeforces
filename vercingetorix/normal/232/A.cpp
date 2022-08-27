#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

//bool test(int n) {
//    int k = 0;
//    while(k*(k+1) <= 2*n) k++;
//    forn(l1,1,k+1) forn(l2,1,k+1) forn(l3,1,k+1) {
//        if(l1*(l1-1) + l2*(l2-1) + l3*(l3-1) == 2*n) {
//            return true;
//        }
//    }
//}

void stress() {
    
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    int k = 2;
    while((k+1)*k*(k-1)/6 <= n) k++;
    vs a(101, string(101, '0'));
    forn(i,0,k) forn(j,0,k) if(i!=j) a[i][j] = '1';
    n -= k*(k-1)*(k-2)/6;
    forn(l1,1,k+1) forn(l2,1,k+1) forn(l3,1,k+1) {
        if(l1*(l1-1) + l2*(l2-1) + l3*(l3-1) == 2*n) {
            forn(i,0,l1) {
                a[k][i] = '1';
                a[i][k] = '1';
            }
            forn(i,0,l2) {
                a[k+1][i] = '1';
                a[i][k+1] = '1';
            }
            forn(i,0,l3) {
                a[k+2][i] = '1';
                a[i][k+2] = '1';
            }
            a.resize(k+3);
            forn(i,0,k+3) a[i].resize(k+3);
            printf("%d\n", k+3);
            for(auto x : a) printf("%s\n", x.c_str());
            exit(0);
        }
    }
    
}