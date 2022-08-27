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
    char c[100500];
    while(t--) {
        int n;
        scanf("%d\n", &n);
        scanf("%s", c);
        int c0 = 0;
        int a = 0;
        forn(i,0,n/2) if(c[i] != c[n-1-i]) {
            a += 1;
            c[i] = '1';
            c[n-1-i] = '1';
        }
        forn(i,0,n) {
            if(c[i]=='0') c0++;
        }
        if(a==0) {
            if(c0 == 0) printf("DRAW\n");
            else if(c0 % 2==0 || c0==1) printf("BOB\n");
            else printf("ALICE\n");
            continue;
        }
        else {
            if(c0%2 == 0) printf("ALICE\n");
            else if(c0==1 && a==1) printf("DRAW\n");
            else printf("ALICE\n");
        }
//        if(c0 == 0) {
//            a+=0;
//        }
//        else if(c0 % 2 == 0) {
//            a-=2;
//        }
//        else if(c0 == 1) {
//            a--;
//        }
//        else {
//            a--;
//        }
//        if(a == 0) printf("DRAW\n");
//        else if(a<0) printf("BOB\n");
//        else printf("ALICE\n");
//
    }
    
    
}