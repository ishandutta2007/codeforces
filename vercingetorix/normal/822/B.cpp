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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    const int INF = 1e9;
    vi ans(n+1,0);
    forn(st,0,m-n+1) {
        vi cand;
        forn(i,0,n) {
            if(s[i] != t[st+i]) cand.pb(i+1);
        }
        if(cand.size() < ans.size()) ans = cand;
    }
//    vvpi d(n+1, vpi(m+1, mp(INF,0)));
//    forn(j,0,m+1) d[0][j] = mp(0,0);
//    forn(i,1,n+1) {
//        forn(j,1,m+1) {
//            d[i][j] = min(mp(d[i][j-1].first, 2), mp(d[i-1][j-1].first + 1,3));
//            if(s[i-1] == t[j-1]) d[i][j] = min(d[i][j], mp(d[i-1][j-1].first, 1));
//        }
//    }
//    vi ans;
//    int ci = n;
//    int cj = m;
//    while(ci > 0) {
//        if(d[ci][cj].second == 2) cj--;
//        else if(d[ci][cj].second == 3) {
//            ci--;
//            cj--;
//            ans.pb(ci);
//        }
//        else if(d[ci][cj].second == 1) {
//            ci--;
//            cj--;
//        }
//    }
    cout<<ans.size()<<endl;
    for(auto x : ans) cout<<x<<' ';
    
}