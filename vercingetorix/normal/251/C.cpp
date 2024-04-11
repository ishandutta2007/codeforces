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
int k;
ll proc(ll x, ll y) {
    vi d(y-x+1,0);
    for(ll a = x+1; a<=y; a++) {
        d[a-x] = d[a-1-x]+1;
        forn(i,2,k+1) {
            ll fr = a - (a%i);
            if(fr>=x) d[a-x] = min(d[a-x], d[fr-x]+1);
        }
    }
    return d[y-x];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll a,b;
    cin>>a>>b>>k;
    int A = 1;
    forn(i,2,k+1) {
        int B = A;
        while(A%i != 0) A+=B;
    }
    if(a-b < A) {
        cout<<proc(b,a);
        return 0;
    }
    ll nb = ((b+A-1)/A)*A;
    ll na = (a/A)*A;
    ll ans = 0;
    ans += proc(b, nb);
    ans += proc(na, a);
    ans += ((na-nb)/A)*proc(0, A);
    cout<<ans;
    
}