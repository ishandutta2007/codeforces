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
vpi cur;
void get(int n) {
    if(n<=1) return;
    int k = n-4;
    get(n-4);
    forn(i,1,k+1) cur.pb(mp(i,k+1));
    cur.pb(mp(k+1,k+2));
    for(int i = k; i>=1; i--) cur.pb(mp(i,k+2));
    forn(i,1,k+1) cur.pb(mp(i,k+3));
    cur.pb(mp(k+3,k+4));
    for(int i = k; i>=1; i--) cur.pb(mp(i,k+4));
    cur.pb(mp(k+1,k+4));
    cur.pb(mp(k+2,k+3));
    cur.pb(mp(k+1,k+3));
    cur.pb(mp(k+2,k+4));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin >> n;
    int m = (n*(n-1))/2;
    if(m%2 == 1) {
        cout<<"NO";
        return 0;
    }
    printf("YES\n");
    get(n);
//    vi x;
//    forn(i,1,n+1) x.pb(i);
//    for(auto p : cur) {
//        swap(x[p.first-1], x[p.second-1]);
//    }
//    for(auto y : x) cout<<y<<' ';
    for(auto x : cur) printf("%d %d\n", x.first, x.second);
    
}