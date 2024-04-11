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
int w[100000];
int s[100001];
int l, r, ql, qr;

int main () {
    scanf ("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
    for (int i = 0; i < n; i++) scanf ("%d", &w[i]);
    s[n] = 0;
    for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + w[i];
    int ans = min (s[0] * l + (n - 1) * ql, s[0] * r + (n - 1) * qr);
    {
        int cur = 0, i = 0, j = n - 1;
        while (i <= j) {
            ans = min (ans, cur + (s[i] - s[j + 1]) * l + (j - i) * ql);
            ans = min (ans, cur + (s[i] - s[j + 1]) * r + (j - i + 1) * qr);
            cur += w[i] * l;
            i++;
            if (i > j) break;
            ans = min (ans, cur + (s[i] - s[j + 1]) * l + (j - i + 1) * ql);
            ans = min (ans, cur + (s[i] - s[j + 1]) * r + (j - i) * qr);
            cur += w[j] * r;
            j--;
        }
        ans = min (ans, cur);
    }   
    {
        int cur = 0, i = 0, j = n - 1;
        while (i <= j) {
            ans = min (ans, cur + (s[i] - s[j + 1]) * l + (j - i + 1) * ql);
            ans = min (ans, cur + (s[i] - s[j + 1]) * r + (j - i) * qr);
            cur += w[j] * r;
            j--;
            if (i > j) break;
            ans = min (ans, cur + (s[i] - s[j + 1]) * l + (j - i) * ql);
            ans = min (ans, cur + (s[i] - s[j + 1]) * r + (j - i + 1) * qr);
            cur += w[i] * l;
            i++;
        }
        ans = min (ans, cur);
    }
    printf ("%d\n", ans);
    return 0;
}