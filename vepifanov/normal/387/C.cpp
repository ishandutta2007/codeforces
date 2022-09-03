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
int x[100001];

int good (int l1, int r1, int l2, int r2) {
    if (r1 - l1 != r2 - l2) re int (r1 - l1 > r2 - l2);
    for (int t = 0; t <= r1 - l1; t++)
        if (s[l1 + t] != s[l2 + t])
            re int (s[l1 + t] > s[l2 + t]);
    re 1;
}

int main () {
    cin >> s;
    for (int i = 0; i < sz (s); i++)
        if (s[i] != '0')
            x[m++] = i;
    x[m] = sz (s);
    for (int i = m - 1; i > 0; i--)
        if (!good (0, x[i] - 1, x[i], x[i + 1] - 1)) {
            printf ("%d\n", m - i);
            re 0;
        }
    printf ("%d\n", m);
    return 0;
}