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
#include <bitset>
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
    scanf("%d %d\n", &n,&m);
    vs a(n);
    forn(i,0,n) {
        getline(cin, a[i]);
    }
    int r,c;
    scanf("%d %d\n",&r,&c);
    vs b(r);
    vector<bitset<800>> ans(n);
    forn(i,0,n) forn(j,0,m) ans[i][j] = 1;
    forn(i,0,r) {
        getline(cin, b[i]);
    }
    vector<vector<bitset<800>>> def(26, vector<bitset<800>>(n));
    forn(k,0,26) {
        forn(i,0,n) {
            forn(j,0,m) {
                if(a[i][j] == char('a'+k)) {
                    int cur = j;
                    while(cur < 800) {
                        def[k][i][cur] = 1;
                        cur+=m;
                    }
                }
            }
        }
    }
    forn(i,0,r) {
        forn(j,0,c) {
            if(b[i][j] == '?') continue;
            int cind = b[i][j] -'a';
            forn(k,0,n) {
                bitset<800> lol = def[cind][k];
                lol >>= j;
                ans[(k+n*r-i)%n] &= lol;
            }
        }
    }
    int num  = 0;
    forn(i,0,n) {
        string st;
        forn(j,0,m) st.pb(char('0'+ans[i][j]));
        printf("%s\n",st.c_str());
    }
    
    
}