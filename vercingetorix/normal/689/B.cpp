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
    vi a(n);
    vvi ret(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) a[i]--;
    deque<int> q;
    vi u(n,0);
    u[0] = 1;
    vi d(n,0);
    q.pb(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        if(v > 0) if(!u[v-1]) {
            d[v-1] = d[v] + 1;
            q.pb(v-1);
            u[v-1]=1;
        }
        if(v < n-1) if(!u[v+1]) {
            d[v+1] = d[v] + 1;
            q.pb(v+1);
            u[v+1]=1;
        }
        if(!u[a[v]]) {
            u[a[v]]=1;
            d[a[v]]=d[v]+1;
            q.pb(a[v]);
        }
    }
    forn(i,0,n) printf("%d ", d[i]);
}