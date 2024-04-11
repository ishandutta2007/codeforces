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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int req(int x) {
    printf("? %d\n", x);
    fflush(stdout);
    int a;
    scanf("%d", &a);
    return a;
}


const int INF =1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi a(n+2,-INF);
    a[0] = INF;
    a[n+1]= INF;
    if(n<100) {
        
        forn(i,1,n+1) a[i] = req(i);
        forn(i,1,n+1) if(a[i] < a[i-1] && a[i] < a[i+1]) {
            printf("! %d\n", i);
            exit(0);
        }
        
    }
    a[1] = req(1);
    a[2] = req(2);
    a[n] = req(n);
    a[n-1] = req(n-1);
    if(a[2] > a[1]) {
        printf("! %d\n", 1);
        exit(0);
    }
    if(a[n-1] > a[n]) {
        printf("! %d\n", n);
        exit(0);
    }
    int l = 1;
    int r = n;
    int m = 2;
    if(a[n-1] < a[m]) m = n-1;
    while(r-l > 2) {
        if(r-m > m-l) {
            int k = (r+m)/2;
            a[k] = req(k);
            if(a[k] < a[m]) {
                l=m;
                m=k;
            }
            else {
                r=k;
            }
        }
        else {
            int k = (l+m)/2;
            a[k] = req(k);
            if(a[k] < a[m]) {
                r=m;
                m=k;
            }
            else {
                l=k;
            }
        }
    }
    printf("! %d\n", m);
}