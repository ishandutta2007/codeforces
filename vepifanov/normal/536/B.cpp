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
#define prev PREV
                         
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
int m;
char h[1000100];
int len;
int x[1000100];
int p[1000100];
int good[1000100];
int d[1000100];
string s;

int main () {
    scanf ("%d%d", &n, &m);
    scanf (" %s", h);
    s = string (h);
    len = sz (s);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &x[i]);
        x[i]--;
    }
    p[0] = -1;
    for (int i = 1; i < len; i++) {
        int k = p[i - 1];
        while (k >= 0 && s[k + 1] != s[i]) k = p[k];
        if (s[k + 1] == s[i])
            k++;
        p[i] = k;   
    }
    int k = len - 1;
    while (k >= 0) {
        good[len - k - 1] = 1;
        k = p[k];
    }
    for (int i = 0; i < m; i++) {
        d[x[i]]++;
        d[x[i] + len]--;
        if (i > 0 && x[i] - x[i - 1] < len && !good[x[i] - x[i - 1]]) {
            printf ("0\n");
            re 0;
        }
    }
    int cur = 1, bal = 0;
    for (int i = 0; i < n; i++) {
        bal += d[i];
        if (!bal) cur = ((ll)cur * 26) % 1000000007;
    }
    printf ("%d\n", cur);
    return 0;
}