#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define next NEXT
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m, u;

string s[2000];
int f[2000];
int l[2000];
int next[1000001][26];
int next_big[2000][26];
char h[1000001];
int was[2000][26];
int last[26];
int q[2000];
ii pos[2001];

string t;

ii get (ii cur, int x) {
    int i = cur.fi;
    int j = cur.se;
    if (j < l[q[i]] && next[f[q[i]] + j][x] < l[q[i]]) {
        j = next[f[q[i]] + j][x] + 1;
        re mp (i, j);
    }   
    i++;
    if (i < m && next_big[i][x] < m) {
        i = next_big[i][x];
        j = next[f[q[i]]][x] + 1;
        re mp (i, j);
    }
    re mp (m, 0);
}

int main () {
    scanf ("%d", &n);
    gets (h);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        gets (h);
        s[i] = string (h);
        l[i] = sz (s[i]);
        f[i] = cur;
        for (int j = 0; j < 26; j++) last[j] = l[i];
        for (int j = l[i] - 1; j >= 0; j--) {
            was[i][s[i][j] - 'a'] = 1;
            last[s[i][j] - 'a'] = j;
            for (int k = 0; k < 26; k++) next[cur + j][k] = last[k];
        }
        cur += l[i];
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &q[i]);
        q[i]--;
    }   
    for (int j = 0; j < 26; j++) last[j] = m;
    for (int j = m - 1; j >= 0; j--) {
        for (int k = 0; k < 26; k++)
            if (was[q[j]][k])
                last[k] = j;
        for (int k = 0; k < 26; k++) next_big[j][k] = last[k];
    }
    gets (h);
    gets (h);
    t = string (h);
    u = sz (t);
    pos[0] = mp (0, 0);
    for (int i = 1; i <= u; i++) pos[i] = mp (m, 0);
    for (int i = 0; i < u; i++)
        for (int j = u - 1; j >= 0; j--) 
            if (pos[j].fi < m) {
                ii tmp = get (pos[j], t[i] - 'a');
                pos[j + 1] = min (pos[j + 1], tmp);
            }
    for (int i = u; i >= 0; i--)
        if (pos[i].fi < m) {
            printf ("%d\n", i);
            re 0;
        }
    return 0;
}