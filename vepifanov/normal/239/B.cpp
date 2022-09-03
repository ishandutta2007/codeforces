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

int n;
int m;
int cnt[10];
string s;

int go (string s) {
    memset (cnt, 0, sizeof (cnt));
    int x = 0, y = 1, last = -1;
    while (true) {
        if (x < 0 || x >= sz (s)) break;
        if (s[x] == '$') {
            x += y;
            continue;
        }
        if (s[x] >= '0' && s[x] <= '9') {
            cnt[s[x] - '0']++;
            if (s[x] == '0') s[x] = '$'; else s[x]--;
        } else {
            if (last != -1 && (s[last] == '<' || s[last] == '>')) s[last] = '$';
            if (s[x] == '<') y = -1; else y = 1;
        }
        last = x;
        x += y;
    }
    for (int i = 0; i < 10; i++) printf ("%d ", cnt[i]);
    printf ("\n");
    re 0;
}

int main () {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        go (s.substr (a, b - a + 1));
    }
    return 0;
}