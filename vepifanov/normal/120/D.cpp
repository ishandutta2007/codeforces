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
int a, b, c;
int x[50][50];

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf ("%d", &x[i][j]);
    scanf ("%d%d%d", &a, &b, &c);
    if (a > b) swap (a, b);
    if (b > c) swap (b, c);
    if (a > b) swap (a, b);
    int ans = 0;
    for (int i = 0; i + 2 < n; i++)
        for (int j = i + 1; j + 1 < n; j++) {
            int A = 0, B = 0, C = 0;
            for (int p = 0; p < n; p++)
                for (int q = 0; q < m; q++)
                    if (p <= i) A += x[p][q]; else
                    if (p <= j) B += x[p][q]; else C += x[p][q];
            if (A > B) swap (A, B);
            if (B > C) swap (B, C);
            if (A > B) swap (A, B);
            ans += int (a == A && b == B && c == C);
        }
    for (int i = 0; i + 2 < m; i++)
        for (int j = i + 1; j + 1 < m; j++) {
            int A = 0, B = 0, C = 0;
            for (int p = 0; p < n; p++)
                for (int q = 0; q < m; q++)
                    if (q <= i) A += x[p][q]; else
                    if (q <= j) B += x[p][q]; else C += x[p][q];
            if (A > B) swap (A, B);
            if (B > C) swap (B, C);
            if (A > B) swap (A, B);
            ans += int (a == A && b == B && c == C);
        }
    printf ("%d\n", ans);
    re 0;
}