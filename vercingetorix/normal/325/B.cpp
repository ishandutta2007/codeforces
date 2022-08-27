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
int k = 0;
ll d2 = 1;
ll n;

bool check(ll m) {
    if(m*(m-1) > 2*n) return true;
    ll rs = n - (m*(m-1))/2;
    if(d2==1) return false;
    if(d2-1 >= rs/m + 1) return true;
    else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    cin >> n;
    vll ans;
    while(k<=60) {
        if(d2-1 > n) break;
        ll r = 2000000001;
        ll l = 1;
        while(r-l > 1) {
            ll m = (r+l)/2;
            if(check(m)) r = m;
            else l = m;
        }
        if(l%2 == 1 && (l*(l-1))/2 + (d2-1)*l == n) ans.pb(d2*l);
        k++;
        d2*=2;
    }
    sort(all(ans));
    if(ans.empty()) cout<<-1;
    else for(auto x : ans) cout<<x<<endl;
}