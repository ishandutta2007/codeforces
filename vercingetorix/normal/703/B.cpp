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
    int n,k;
    scanf("%d %d", &n, &k);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    vi cap(n,0);
    forn(i,0,k) {
        int x;
        scanf("%d", &x);
        x--;
        cap[x] = 1;
    }
    ll sumO = 0;
    ll sumC = 0;
    forn(i,0,n) sumC += (ll)cap[i] * a[i];
    forn(i,0,n) sumO += (ll)(1-cap[i]) * a[i];
    ll ans = 0;
    ll sumCC = 0;
    forn(i,0,n) if(cap[i]) sumCC+= (ll)a[i] * (sumC-a[i]);
    sumCC/=2;
    ans = sumCC + sumO*sumC;
    forn(i,0,n-1) {
        if(cap[i]+cap[i+1]==0) ans+=(ll)a[i]*a[i+1];
    }
    if(cap[n-1]+cap[0]==0) ans+=(ll)a[0]*a[n-1];
    cout<<ans;
    
}