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
#include <cassert>

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

const int N = 10;

int n;
int m;
int x[100];

int check (int x) {
    int y = sqrt (x);
    while (y * y > x) y--;
    while ((y + 1) * (y + 1) <= x) y++;
    re int (y * y == x);
}

vi gen (int n, int s, int N) {
    if (n == 0) {
        if (check (s)) {
            vi v;   
            for (int i = 0; i < N; i++) v.pb (x[i]);
            re v;
        }
        re vector<int>();
    }
    for (int i = 1; i <= ::N; i++) {
        x[n - 1] = i;
        vi v = gen (n - 1, s + i * i, N);
        if (!v.empty ()) re v;
    }   
    re vector<int>();
}

int main () {
    scanf ("%d%d", &n, &m);
    vi a = gen (n, 0, n);
    vi b = gen (m, 0, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf ("%d ", a[i] * b[j]);
        printf ("\n");
    }
    return 0;
}