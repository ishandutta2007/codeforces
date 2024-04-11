#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int d[201][201][201];
int mv[201][201][201];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c1[300], c2[300];
    scanf("%s", c1);
    scanf("%s", c2);
    string s(c1);
    string t(c2);
    int n1 = s.size();
    int n2 = t.size();
    forn(i,0,201) d[n1][n2][i] = i;
    for(int i = n1; i>=0; i--) {
        for(int j = n2; j>=0; j--) {
            if(i==n1 && j==n2) continue;
            forn(p,0,201) {
                if(j==n2) {
                    if(p==0 && s[i] == ')') {
                        d[i][j][p] = 2 + d[i+1][j][p];
                    }
                    else {
                        int st = 1;
                        if(s[i] == ')') st = -1;
                        d[i][j][p] = 1 + d[i+1][j][p+st];
                    }
                    mv[i][j][p] = 1;
                }
                else if(i == n1) {
                    string cand;
                    if(p==0 && t[j] == ')') {
                        d[i][j][p] = 2 + d[i][j+1][p];
                    }
                    else {
                        int st = 1;
                        if(t[j] == ')') st = -1;
                        d[i][j][p] = 1 + d[i][j+1][p+st];
                    }
                    mv[i][j][p] = -1;
                }
                else if(s[i] != t[j]){
                    int cand1;
                    if(p==0 && s[i] == ')') {
                        cand1 = 2 + d[(i+1)][j][p];
                    }
                    else {
                        int st = 1;
                        if(s[i] == ')') st = -1;
                        cand1 = 1 + d[(i+1)][j][p+st];
                    }
                    int cand2;
                    if(p==0 && t[j] == ')') {
                        cand2 = 2 + d[i][j+1][p];
                    }
                    else {
                        int st = 1;
                        if(t[j] == ')') st = -1;
                        cand2 = 1 + d[i][j+1][p+st];
                    }
                    d[i][j][p] = min(cand1,cand2);
                    if(cand1 <= cand2) mv[i][j][p] = 1;
                    else mv[i][j][p] = -1;
                }
                else {
                    if(p==0 && s[i] == ')') {
                        d[i][j][p] = 2 + d[(i+1)][j+1][p];
                    }
                    else {
                        int st = 1;
                        if(s[i] == ')') st = -1;
                        d[i][j][p] = 1 + d[(i+1)][j+1][p+st];
                    }
                    mv[i][j][p] = 0;
                }
            }
        }
    }
    string ans;
    int x = 0;
    int y = 0;
    int cur = 0;
    while(x!=n1 || y!=n2) {
        if(mv[x][y][cur] == 0) {
            if(s[x] == ')') {
                if(cur == 0) ans.pb('(');
                else cur--;
            }
            else cur++;
            ans.pb(s[x]);
            x++;
            y++;
        }
        else if(mv[x][y][cur] == 1) {
            if(s[x] == ')') {
                if(cur == 0) ans.pb('(');
                else cur--;
            }
            else cur++;
            ans.pb(s[x]);
            x++;
        }
        else {
            if(t[y] == ')') {
                if(cur == 0) ans.pb('(');
                else cur--;
            }
            else cur++;
            ans.pb(t[y]);
            y++;
        }
    }
    forn(i,0,cur) ans.pb(')');
    cout<<ans;
    
    
}