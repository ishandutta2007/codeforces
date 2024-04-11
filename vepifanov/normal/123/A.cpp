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

int n, r = 0;
int m;
string s;
int f[1001];
int p[1001];
int q[1001];
int was[1001];
vii w;

int cnt[26];

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int main () {
    cin >> s;   
    n = sz (s);
    for (int i = 2; i <= n; i++)
        if (!f[i]) {
            q[r++] = i;
            for (int j = 2 * i; j <= n; j += i) f[j] = 1;
        }
    for (int i = 0; i < n; i++) p[i] = i;
    for (int j = 0; j < r && 2 * q[j] <= n; j++) 
        for (int i = 2; i * q[j] <= n; i++) {
            int a = gp ((i - 1) * q[j] - 1), b = gp (i * q[j] - 1);
            if (rand () & 1) p[a] = b; else p[b] = a;
        }
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    for (int i = 0; i < n; i++) 
        if (!was[i]) {
            int k = 0;
            for (int j = 0; j < n; j++)
                if (gp (i) == gp (j)) {
                    was[j] = 1;
                    k++;
                }   
            w.pb (mp (k, gp (i)));
        }
    sort (all (w));
    reverse (all (w));
    for (int i = 0; i < sz (w); i++) {
        int j = -1;
        for (int k = 0; k < 26; k++)
            if (cnt[k] >= w[i].fi) {
                j = k;
                break;
            }
        if (j == -1) {
            printf ("NO\n");
            re 0;
        }
        cnt[j] -= w[i].fi;
        for (int k = 0; k < n; k++)
            if (gp (k) == w[i].se)
                s[k] = char (j + 'a');
    }
    printf ("YES\n%s\n", s.c_str ());
    return 0;
}