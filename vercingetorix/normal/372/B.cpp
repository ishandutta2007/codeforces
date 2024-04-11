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
    int n,m,q;
    scanf("%d %d %d\n", &n, &m, &q);
    vs s(n);
    forn(as, 0, n) getline(cin, s[as]);
    vector<vvvi> cnt(n, vvvi(n, vvi(m, vi(m,0))));
    vvi ch(n, vi(m,0));
    forn(j,0,m) {
        int sum = 0;
        forn(i,0,n) {
            sum += int(s[i][j] -'0');
            ch[i][j] = sum;
        }
    }
    forn(u,0,n) forn(d,u,n) {
        forn(l,0,m) forn(r,l,m) {
            int cur = 0;
            int pt = 0;
            forn(p,l,r+1) {
                int test = ch[d][p];
                if(u>0) test -= ch[u-1][p];
                if(test==0) cur++;
                else cur = 0;
                pt += cur;
            }
            cnt[u][d][l][r] = pt;
        }
    }
    forn(i,0,q) {
        int U,D,l,r;
        int ans = 0;
        scanf("%d %d %d %d", &U, &l,&D,&r);
        U--; D--; l--; r--;
        forn(u,U,D+1) {
            forn(d,u,D+1) {
                ans += cnt[u][d][l][r];
            }
        }
        printf("%d\n", ans);
        
    }
    
}