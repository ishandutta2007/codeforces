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
map<char ,char> to;
vs trans(vs x) {
    int n = x.size();
    int m = x[0].size();
    vs res(m, string(n,'.'));
    
    
    forn(i,0,n) forn(j,0,m) {
        res[j][i] = to[x[i][j]];
    }
    return res;
}

vpi unify(vs a) {
    vpi res;
    int n = a.size();
    int m = a[0].size();
    forn(i,0,n) {
        for(int j = 0; j < m; j+=2) {
            if(a[i][j] != 'L') {
                int cx = i;
                int cy = j;
                int sx = 0;
                int sy = 1;
                while(a[cx][cy] != a[cx+sx][cy+sy]) {
                    cx+=sx;
                    cy+=sy;
                    swap(sx,sy);
                }
                while(1) {
                    res.pb(mp(cx,cy));
                    if(a[cx][cy] == 'U') {
                        a[cx][cy]='L';
                        a[cx+1][cy]='L';
                        a[cx][cy+1]='R';
                        a[cx+1][cy+1]='R';
                    }
                    else {
                        a[cx][cy]='U';
                        a[cx+1][cy]='D';
                        a[cx][cy+1]='U';
                        a[cx+1][cy+1]='D';
                    }
                    swap(sx,sy);
                    if(cx==i && cy==j) break;
                    cx-=sx;
                    cy-=sy;
                };
            }
        }
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    to['R']='D';
    to['L']='U';
    to['D']='R';
    to['U']='L';
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs a(n), b(n);
    forn(i,0,n) getline(cin, a[i]);
    forn(i,0,n) getline(cin, b[i]);
    bool sw = false;
    if(m%2 != 0) {
        sw = true;
        a = trans(a);
        b = trans(b);
        swap(m,n);
    }
    vpi u1 = unify(a);
    vpi u2 = unify(b);
    vpi ans = u1;
    reverse(all(u2));
    for(auto x : u2) ans.pb(x);
    for(auto & x : ans) {
        x.first ++;
        x.second ++;
    }
    if(sw) {
        for(auto & x : ans) swap(x.first, x.second);
    }
    printf("%d\n", ans.size());
    for(auto x : ans) {
        printf("%d %d\n", x.first, x.second);
    }
    
    
    
}