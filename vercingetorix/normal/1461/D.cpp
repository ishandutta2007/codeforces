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
vi a;
vll s;
set<ll> can;

void go(int l, int r) {
    ll val = s[r];
    if (l>0) val-=s[l-1];
    can.insert(val);
    if(a[l]==a[r]) {
        return;
    }
    int mv = (a[l] + a[r])/2;
    int m = upper_bound(a.begin() + l, a.begin() + r + 1, mv) - a.begin();
    go(l,m-1);
    go(m,r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    forn(af,0,t) {
        can.clear();
        int n,q;
        scanf("%d %d", &n, &q);
        a.resize(n);
        forn(i,0,n) scanf("%d",&a[i]);
        sort(all(a));
        s.resize(n);
        ll cur = 0;
        forn(i,0,n) {
            cur += a[i];
            s[i] = cur;
        }
        go(0,n-1);
        forn(i,0,q) {
            ll f;
            scanf("%lld", &f);
            if(can.find(f) != can.end()) {
                printf("Yes\n");
            }
            else printf("No\n");
        }
        
    }
}