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
    int n,k;
    scanf("%d %d", &n, &k);
    vi a(n);
    ll sum = 0;
    forn(i,0,n) {
        scanf("%d", &a[i]);
        sum += (ll) a[i];
    }
    sort(all(a));
    vi ideal(n, sum/n);
    forn(i,0,sum%n) ideal[n-1-i]++;
    ll exs= 0;
    forn(i,0,n) if(a[i]>ideal[i]) exs+=(ll)(a[i]-ideal[i]);
    if(exs<=k) {
        if(sum%n==0) cout<<0;
        else cout<<1;
        return 0;
    }
    int l = 0;
    int r = 1000000000;
    while(r-l>1) {
        int m = (r+l)/2;
        ll used = 0;
        forn(i,0,n) {
            if (a[i] > m) used += (a[i]-m);
        }
        if(used<=k) r=m;
        else l = m;
    }
    int tmax = r;
    l = 0;
    r = 1000000001;
    while(r-l>1) {
        int m = (r+l)/2;
        ll used = 0;
        forn(i,0,n) {
            if (a[i] < m) used += (m-a[i]);
        }
        if(used<=k) l=m;
        else r = m;
    }
    int tmin = l;
    cout<<tmax-tmin;
}