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
    int n;
    scanf("%d", &n);
    vvll a(n, vll(n,0));
    vll d2(1,1);
    forn(i,0,60) d2.pb(d2.back()*2);
    forn(i,0,n) forn(j,0,n) {
        if(i%2 == 1) a[i][j] = d2[i+j];
    }
    forn(i,0,n) {
        forn(j,0,n){
            printf("%lld", a[i][j]); if(j<n-1) printf(" ");
        }
        printf("\n");
    }
    fflush(stdout);
    int q;
    scanf("%d", &q);
    while(q--) {
        ll x;
        scanf("%lld", &x);
        int i = 0;
        int j = 0;
        vpi ans;
//        ans.pb(mp(0,0));
        while(i+j < 2*n-2) {
            ans.pb(mp(i+1, j+1));
            if(i==n-1) j++;
            else if(j==n-1) i++;
            else {
                if(i%2==1) {
                    if(x&d2[i+j+1]) j++;
                    else i++;
                }
                else {
                    if(x&d2[i+j+1]) i++;
                    else j++;
                }
            }
        }
        ans.pb(mp(n,n));
        for(auto x:ans) printf("%d %d\n", x.first, x.second);
        fflush(stdout);
    }
    
    
}