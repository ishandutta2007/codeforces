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
    int h,w;
//    cin>>h>>w;
    scanf("%d %d\n", &h, &w);
    vvi a(h, vi(w));
    forn(i,0,h) {
        string s;
        //cin>>s;
        getline(cin,s);
        forn(j,0,w) {
            a[i][j] = 0;
            if(s[j]=='.') a[i][j] = 1;
        }
    }
    vvi r(h,vi(w,0));
    vvi d(h,vi(w,0));
    forn(i,0,h) forn(j,0,w-1) if(a[i][j]+a[i][j+1] == 2) r[i][j] = 1;
    forn(i,0,h-1) forn(j,0,w) if(a[i][j]+a[i+1][j] == 2) d[i][j] = 1;
    vvi cr(h,vi(w, 0));
    vvi cd(h,vi(w, 0));
    forn(i,0,h) {
        int sr=0;
        int sd=0;
        forn(j,0,w) {
            sr+=r[i][j];
            sd+=d[i][j];
            cr[i][j] = sr;
            cd[i][j] = sd;
        }
    }
    int q;
    scanf("%d", &q);
    forn(iasf,0,q) {
        int r1,c1,r2,c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--;
        c1--;
        r2--;
        c2--;
        int ans = 0;
        if(c2>0) {
            forn(i,r1,r2+1) {
                ans += cr[i][c2-1];
            }
        }
        if(c1>0) {
            forn(i,r1,r2+1) {
                ans -= cr[i][c1-1];
            }
        }
        forn(i,r1,r2) {
            ans += cd[i][c2];
        }
        if(c1>0) {
            forn(i,r1,r2) {
                ans -= cd[i][c1-1];
            }
        }
        printf("%d\n", ans);
    }
    
}