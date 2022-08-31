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
    scanf("%d\n", &n);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    scanf("\n");
    vector<string> s(n);
    vector<string> sr(n);
    forn(i,0,n) getline(cin,s[i]);
    forn(i,0,n) {
        sr[i] = s[i];
        reverse(all(sr[i]));
    }
    vll d(2);
    ll INF = 100000ll*100000ll*100000ll;
    d[0] = 0;
    d[1] = a[0];
    forn(i,1,n) {
        vll d2(2,INF);
        if(s[i]>=s[i-1]) d2[0] = min(d2[0], d[0]);
        if(s[i]>=sr[i-1]) d2[0] = min(d2[0], d[1]);
        if(sr[i]>=s[i-1]) d2[1] = min(d[0]+(ll)a[i], d2[1]);
        if(sr[i]>=sr[i-1]) d2[1] = min(d2[1], d[1]+(ll)a[i]);
        d=d2;
    }
    ll ans = min(d[0], d[1]);
    if(ans<INF) cout<<ans;
    else cout<<-1;
    
    
    
}