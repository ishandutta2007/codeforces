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
    int n,a,b;
    cin>>n>>a>>b;
    vi x(n), y(n);
    forn(i,0,n) cin>>x[i]>>y[i];
    int ans = 0;
    forn(i,0,n) forn(j,i+1,n) {
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[i], y[i]);
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[j], y[j]);
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[i], y[i]);
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[j], y[j]);
        swap(a,b);
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[i], y[i]);
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[j], y[j]);
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[i], y[i]);
        if(x[i]+x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
        swap(x[j], y[j]);
        swap(a,b);
    }
    cout<<ans;
    
    
}