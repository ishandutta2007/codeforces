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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vvi a(n, vi(k));
    int ind = -1;
    forn(i,0,n) {
        int sum = 0;
        forn(j,0,k) {
            scanf("%d", &a[i][j]);
            sum+=a[i][j];
        }
        if(sum == 0) {
            cout<<"YES";
            return 0;
        }
        if(sum == 1) ind = i;
    }
    if(ind>=0) {
        int tm;
        forn(j,0,k) if(a[ind][j] == 1) tm = j;
        forn(i,0,n) if(a[i][tm] == 0) {
            cout<<"YES";
            return 0;
        }
        cout<<"NO";
        return 0;
    }
    if(k<4) {
        cout<<"NO";
        return 0;
    }
    vi has(16,0);
    forn(i,0,n) {
        int sum = 0;
        forn(j,0,4) sum += a[i][j]*(1<<j);
        has[sum] = 1;
    }
    forn(i,0,16) if(has[i] && has[15-i]) {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    
    
}