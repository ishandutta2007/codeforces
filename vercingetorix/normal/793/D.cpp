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
int d[80][80][81];
const int INF = 1e9;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,80) forn(j,0,80) forn(u,0,81) d[i][j][u] = INF;
    int n,k,m;
    cin>>n>>k;
    cin>>m;
    vvi dif(n, vi(n,INF));
    forn(i,0,m) {
        int u,v,slo;
        cin>>u>>v>>slo;
        dif[u-1][v-1] = min(dif[u-1][v-1], slo);
    }
    forn(i,0,n) forn(j,0,n) d[i][j][1] = 0;
    forn(num,2,k+1) {
        forn(dist,1,n) {
            forn(s,0,n) {
                if(s-dist>=0) {
                    d[s][s-dist][num] = min(d[s][s-dist+1][num], d[s][s-dist][num]);
                    forn(s1,s-dist,s) {
                        if(dif[s][s1] < INF) {
                            d[s][s-dist][num] = min(d[s][s-dist][num], dif[s][s1] + d[s1][s-dist][num-1]);
                            d[s][s-dist][num] = min(d[s][s-dist][num], dif[s][s1] + d[s1][s-1][num-1]);
                        }
                    }
                }
                if(s+dist<n) {
                    d[s][s+dist][num] = min(d[s][s+dist-1][num], d[s][s+dist][num]);
                    forn(s1,s+1,s+dist+1) {
                        if(dif[s][s1] < INF) {
                            d[s][s+dist][num] = min(d[s][s+dist][num], dif[s][s1] + d[s1][s+dist][num-1]);
                            d[s][s+dist][num] = min(d[s][s+dist][num], dif[s][s1] + d[s1][s+1][num-1]);
                        }
                    }
                }
            }
        }
    }
    int ans = INF;
    forn(i,0,n) forn(j,0,n) ans = min(ans, d[i][j][k]);
    if(ans==INF) ans = -1;
    cout<<ans;
    
    
}