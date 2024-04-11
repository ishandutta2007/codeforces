#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

ll sq3(ll x) {
    ll l = 1;
    ll r = 1000001;
    while(r-l>1) {
        ll m = (r+l)/2;
        if(m*m*m <= x) l = m;
        else r = m;
    }
    if(l*l*l == x) return l;
    else return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    forn(i,0,n) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        ll d = sq3(a*b);
        if(d==-1) printf("No\n");
        else if(a%d==0 && b%d == 0) printf("Yes\n");
        else printf("No\n");
    }
    
}