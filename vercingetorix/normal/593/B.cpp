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
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

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
    ll x1,x2;
    scanf("%lld %lld", &x1, &x2);
    vector<pair<pll, int>> a1, a2;
    forn(i,0,n) {
        ll k,b;
        scanf("%lld %lld", &k, &b);
        a1.pb(mp(mp(k*x1+b, k*x2+b), i));
        a2.pb(mp(mp(k*x2+b, k*x1+b), i));
    }
    sort(all(a1));
    sort(all(a2));
    forn(i,0,n) {
        if(a1[i].second != a2[i].second) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}