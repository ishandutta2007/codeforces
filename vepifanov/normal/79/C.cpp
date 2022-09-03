#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
string s, w[10];
int mleft[100000];

int main() {
        cin >> s >> n;
        m = sz (s);
        for (int i = 0; i < n; i++) cin >> w[i];
        for (int i = 0; i < n; i++) mleft[i] = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i + sz (w[j]) <= m) {
                    int ok = 1;
                    for (int t = 0; t < sz (w[j]); t++)
                        if (s[i + t] != w[j][t])
                            ok = 0;
                    if (ok) mleft[i + sz (w[j]) - 1] = max (mleft[i + sz (w[j]) - 1], i + 1);
                }
    int cur = 0, res = 0, len = 0;
    for (int i = 0; i < m; i++) {
        cur = max (cur, mleft[i]);
        if (i - cur + 1 > len) { res = cur; len = i - cur + 1; }
    }
    printf ("%d %d\n", len, res);
    return 0;
}