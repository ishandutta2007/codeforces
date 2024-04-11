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
    int n,q,c;
    scanf("%d %d %d", &n, &q,&c);
    vector<vvi> ds;
    vi x(n), y(n), s(n);
    forn(i,0,n) scanf("%d %d %d", &x[i], &y[i], &s[i]);
    forn(st,0,c+1) {
        vvi dcell(101, vi(101, 0));
        vvi dx(101, vi(101, 0));
        vvi dxy(101, vi(101, 0));
        forn(i,0,n) if(s[i]>0) dcell[x[i]][y[i]] += s[i];
        forn(i,1,101) {
            forn(j,1,101) {
                dx[i][j] = dx[i-1][j] + dcell[i][j];
            }
        }
        forn(i,1,101) {
            forn(j,1,101) {
                dxy[i][j] = dxy[i][j-1] + dx[i][j];
            }
        }
        ds.pb(dxy);
        forn(i,0,n) {
            if (s[i] == c) s[i] = 0;
            else s[i]++;
        }
    }
    forn(i,0,q) {
        int t,x1,y1,x2,y2;
        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
        t = t%(1+c);
        printf("%d\n", ds[t][x2][y2] - ds[t][x2][y1-1] - ds[t][x1-1][y2] + ds[t][x1-1][y1-1]);
    }
    
}