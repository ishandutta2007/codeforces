#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <bitset>
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
    int n,m;
    scanf("%d %d", &n, &m);
    vpi p;
    vector<bitset<4000>> a(n);
    forn(i,0,n) a[i].set(n+i);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x,&y);
        x--;
        y--;
        a[x].set(y);
        p.pb(mp(x,y));
    }
    forn(i,0,n) {
        forn(j,i,n) {
            if(a[j][i]) {
                swap(a[i], a[j]);
            }
        }
        forn(j,i+1,n) if(a[j][i]) a[j] ^= a[i];
    }
    forn(i,0,n) {
        forn(j,i+1,n) {
            if(a[i][j]) a[i] ^= a[j];
        }
    }
    forn(i,0,m) {
        int x = p[i].first;
        int y = p[i].second;
        if(a[y][n+x]) printf("NO\n");
        else printf("YES\n");
    }
    
    
    
}