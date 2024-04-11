#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <list>
#include <map>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

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
    int n,m,k;
    string s;
    ll ans = 0;
    scanf("%d", &n);
    vi a(n);
    vi b(n);
    vpi ab;
    forn(i,0,n) {
        scanf("%d %d", &a[i], &b[i]);
        ab.pb(mp(a[i],b[i]));
    }
    //ab.pb(mp(-2000000,0));
    sort(all(ab));
    vi dest(n, 0);
    forn(i, 0, n) {
        auto x = lower_bound(ab.begin(), ab.begin() + i, mp(ab[i].first - ab[i].second, 0));
        int dest2 = (ab.begin() + i) - x;
        if(x!=ab.begin()) dest2+=dest[x-ab.begin()-1];
        dest[i]=dest2;
    }
    int best=dest[n-1];
    for(int i = 0; i<n; i++) best=min(best,dest[i]+n-1-i);
    cout<<best;
}