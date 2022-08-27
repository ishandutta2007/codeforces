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
    int n,s;
    scanf("%d %d", &n, &s);
    readv(a,n);
    sort(all(a));
    int ans = n;
    int d2 = 1;
    int diff = 1;
    forn(k,0,30) {
        if(ll(k)*ll(n) > ll(8*s)) break;
        int l = 0;
        int r = 0;
        diff = 0;
        while(l<n) {
            while(r<n) {
                if(r==l) {
                    r = l+1;
                    diff = 1;
                }
                else if(a[r] == a[r-1]) r++;
                else if(diff+1<=d2) {
                    r++;
                    diff++;
                }
                else break;
            }
            ans = min(ans, n-(r-l));
            l++;
            if(l==n) break;
            if(l==r) diff--;
            else if(a[l] != a[l-1]) diff--;
        }
        d2*=2;
        
    }
    cout<<ans;
    
}