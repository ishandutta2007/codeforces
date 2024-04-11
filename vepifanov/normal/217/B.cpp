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
string s;
char res[1000010];
char cur[1000010];
int ans;


int go (int a, int b) {
    int k = 0;
    while (a > 0 && b > 0 && k <= m)
        if (a >= b) { cur[k++] = 'T'; a -= b; } else { cur[k++] = 'B'; b -= a; }
    if (k != m || a != 0 || b != 1) re 0;
    reverse (cur, cur + k);
    int tmp = 0;
    for (int i = 1; i < k; i++)
        if (cur[i] == cur[i - 1])
            tmp++;
    if (tmp < ans) {
        ans = tmp;
        for (int i = 0; i < k; i++)
            res[i] = cur[i];
    }
    re 0;
}

int main () {
    cin >> m >> n;
    ans = n + 1;
    for (int i = 0; i <= n; i++) {
        go (i, n);
        go (n, i);
    }   
    if (ans == n + 1) printf ("IMPOSSIBLE\n"); else {
        printf ("%d\n", ans);
        string res = "";
        for (int i = 0; i < m; i++) res += ::res[i];
        printf ("%s\n", res.c_str ());
    }
    return 0;
}