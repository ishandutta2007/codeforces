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
char c[200500];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d\n", &n, &k);
    
    scanf("%s", c);
    vvi u(k);
    int can = 1;
    int hulk = 0;
    for(int i = k; i<n; i++) {
        if(c[i] > c[i-k] && hulk == 0) {
            can = 0;
            break;
        }
        else if(c[i] < c[i-k]) {
            hulk = 1;
        }
        c[i] = c[i-k];
    }
    if(can == 0) {
        int pt = k-1;
        while(pt >= 0 && c[pt] == '9') {
            c[pt--] = '0';
        }
        c[pt]++;
        forn(i,0,k) {
            for(int j = i + k; j <n; j+=k) {
                c[j] = c[i];
            }
        }
    }
    printf("%d\n", n);
    forn(i,0,n) {
        printf("%c", c[i]);
//        if(i!=n-1) printf(" ");
    }
    
    
    
    
}