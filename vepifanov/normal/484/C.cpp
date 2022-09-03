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
int p[1000000];
int q[1000000];
int w[1000000];
string s;

int main () {
    cin >> s;
    n = sz (s);
    scanf ("%d", &m);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int k, d;
        scanf ("%d%d", &k, &d);
        for (int i = 0; i < n; i++) q[i] = i;
        int r = 0;
//      printf ("%d\n", d);
        for (int i = 0; i < d; i++)
            for (int j = i; j < k; j += d)
                q[j] = r++;
        for (int i = 0; i < n; i++) q[i] = (q[i] + n - 1) % n;
        int t = n - k + 1;
        while (t) {
            if (t & 1) {
                for (int i = 0; i < n; i++)
                    w[i] = q[p[i]];
                for (int i = 0; i < n; i++)
                    p[i] = w[i];
            }
            for (int i = 0; i < n; i++)
                w[i] = q[q[i]];
            for (int i = 0; i < n; i++)
                q[i] = w[i];
            t /= 2;
        }
        for (int i = 0; i < n; i++) p[i] = (p[i] + n - (k - 1)) % n;
        for (int i = 0; i < n; i++) q[p[i]] = i;
//      for (int i = 0; i < n; i++) printf ("%d ", q[i]);
//      printf ("\n");
        for (int i = 0; i < n; i++) printf("%c", s[q[i]]);
        printf ("\n");
    }
    return 0;
}