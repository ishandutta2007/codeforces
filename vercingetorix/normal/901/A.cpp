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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    n++;
    readv(a,n);
    vi par1;
    vi par2;
    forn(i,0,n-1) {
        if(a[i] > 1 && a[i+1] > 1) {
            printf("ambiguous\n");
            int pf = 1;
            vi st(n+1, 1);
            st[0] = 1;
            par1.pb(0);
            forn(j,1,n) {
                st[j+1] = st[j];
                forn(k,0,a[j]) par1.pb(st[j]), st[j+1]++;
            }
            par2 = par1;
            par2[st[i+1] + 1] = st[i] + 1;
            forn(i,0,st[n]) printf("%d ", par1[i]); printf("\n");
            forn(i,0,st[n]) printf("%d ", par2[i]); printf("\n");
            return 0;
        }
    }
    printf("perfect");
    
}