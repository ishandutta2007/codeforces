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
int d[101][101][101];
int p[101][101][101];
int pf[101];
int nk[101][26];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    string s1,s2,v;
    forn(i,0,101)forn(j,0,101)forn(k,0,101) {
        d[i][j][k] = -1000;
        p[i][j][k] = -1000;
    }
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, v);
    
    n=v.size();
    for (int i=1; i<n; ++i) {
        int j = pf[i-1];
        while (j > 0 && v[i] != v[j])
            j = pf[j-1];
        if (v[i] == v[j])  ++j;
        pf[i] = j;
    }
    pf[0] = -1;
//    vvvi d(110, vvi(110, vi(110, -1)));
//    vvvi p(110, vvi(110, vi(110, -1000)));
    forn(k,0,n) {
        forn(c,0,26) {
            int cur = k;
            while(cur>=0 && v[cur] != char('A' + c)) {
                if(cur>0)cur = pf[cur-1];
                else cur = -1;
            }
            if(cur == -1 && v[0] == char('A' + c)) cur = 0;
            nk[k][c] = cur;
        }
    }
    forn(i,0,s1.size() + 1) {
        forn(j,0,s2.size() + 1) {
            forn(k,0,v.size()) {
                if(i==0 || j==0) {
                    d[i][j][0] = 0;
                }
//                if(d[i][j][k+1] < d[i][j][k]) {
//                    d[i][j][k+1] = d[i][j][k];
//                    p[i][j][k+1] = 4;
//                }
                if(d[i][j][k] < k) continue;
                if(i<s1.size() && d[i][j][k] > d[i+1][j][k]) {
                    d[i+1][j][k] = d[i][j][k];
                    p[i+1][j][k] = 1;
                }
                if(j<s2.size() && d[i][j][k] > d[i][j+1][k]) {
                    d[i][j+1][k] = d[i][j][k];
                    p[i][j+1][k] = 2;
                }
                if(i<s1.size() && j<s2.size() && s1[i] == s2[j]) {
//                    int cur = k;
//                    while(cur>=0 && v[cur] != s1[i]) {
//                        cur = pf[cur];
//                    }
                    int cur = nk[k][s1[i]-'A'];
                    if(d[i+1][j+1][cur+1] < d[i][j][k] + 1) {
                        d[i+1][j+1][cur+1] = d[i][j][k] + 1;
                        p[i+1][j+1][cur+1] = -k;
                    }
//                    if(d[i+1][j+1][k+1] < d[i][j][k] + 1) {
//                        d[i+1][j+1][k+1] = d[i][j][k] + 1;
//                        p[i+1][j+1][k+1] = -2;
//                    }
//                    if(v[k] != s1[i] && d[i+1][j+1][k] < d[i][j][k] + 1) {
//                        d[i+1][j+1][k] = d[i][j][k] + 1;
//                        p[i+1][j+1][k] = -1;
//                    }
                }
                
            }
        }
    }
    int x = s1.size();
    int y = s2.size();
//    int z = v.size() - 1;
    int z = 0;
    forn(i,0,v.size()) if(d[x][y][i] > d[x][y][z]) z = i;
    string ans;
    while(x>0 && y>0) {
//        printf("%d %d %d\n", x,y,z);
        if(p[x][y][z] == 4) {
            z--;
        }
        else if(p[x][y][z] == 1) {
            x--;
        }
        else if(p[x][y][z] == 2) {
            y--;
        }
        else if(p[x][y][z] <= 0) {
            z = -p[x][y][z];
            x--;
            y--;
            
            ans.pb(s1[x]);
        }
//        else if(p[x][y][z] == -2) {
//            x--;
//            y--;
//            ans.pb(s1[x]);
//            z--;
//        }
    }
    reverse(all(ans));
    
    if(ans.empty()) cout<<0;
    else cout<<ans;
    
}