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
int st[10][100001];
int sum[100001];
int k, w;

int main () {
    scanf ("%d%d%d", &n, &k, &w);
    cin >> s;
    for (int i = n - 1; i >= 0; i--) {
        for (int t = 0; t < k; t++)
            st[t][i] = st[t][i + 1] + int (i % k == t && s[i] == '1');
        sum[i] = sum[i + 1] + s[i] - '0';
    }   
    for (int i = 0; i < w; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        int all = sum[a] - sum[b + 1];
        int cur = st[b % k][a] - st[b % k][b + 1];
        int len = (b - a + 1) / k;
        printf ("%d\n", all - cur + (len - cur));
    }
    return 0;
}