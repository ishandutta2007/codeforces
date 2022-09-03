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
int m, x;
string w[51];
int can[256];
string s;

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] != 'S')
                can[w[i][j]] = 1;
            else
            for (int p = 0; p < n; p++)
                for (int q = 0; q < m; q++) 
                    if (w[p][q] != 'S' && sqr (i - p) + sqr (j - q) <= sqr (x))
                        can[w[p][q] - 'a' + 'A'] = 1;
                    else
                    if (w[p][q] != 'S' && can[w[p][q] - 'a' + 'A'] == 0)
                        can[w[p][q] - 'a' + 'A'] = 2;                   
    int q;
    cin >> q >> s;
    int ans = 0;
    for (int i = 0; i < sz (s); i++)
        if (can[s[i]] == 0) {
            printf ("-1\n");
            re 0;
        } else
        ans += can[s[i]] - 1;
    printf ("%d\n", ans);   
    return 0;
}