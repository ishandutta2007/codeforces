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
    map<ll, ll> cost;
    cin>>n;
    forn(i,0,n) {
        int t;
        cin>>t;
        if(t==1) {
            ll u,v,w;
            cin>>v>>u>>w;
            while(u!=v) {
                if(u>v) {
                    cost[u]+=w;
                    u/=2;
                }
                else {
                    cost[v]+=w;
                    v/=2;
                }
            }
        }
        if(t==2) {
            ll v,u;
            cin>>v>>u;
            ll ans = 0;
            while(u!=v) {
                if(u>v) {
                    ans+=cost[u];
                    u/=2;
                }
                else {
                    ans+=cost[v];
                    v/=2;
                }
            }
            cout<<ans<<endl;
        }
    }
}