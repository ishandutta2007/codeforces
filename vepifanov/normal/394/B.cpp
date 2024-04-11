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
int p, x;
int y[1000000];
int a[1000000];
int A[1000000];

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int main () {
    scanf ("%d%d", &p, &x);
    int cur = 0, z = 10 * x - 1;
    for (int i = 0; i + 2 < p; i++) {
        y[i] = 9;
        cur = (cur * 10 + 9) % z;
    }   
    y[p - 2] = 10 - x;
    cur = (cur * 10 + (10 - x)) % z;
    int d = gcd (cur, z);
    int b = z / d;
    if (b < 10) {
        int r = 0;
        cur = 0;
        for (int i = 0; i < p - 1; i++) {
            cur = cur * 10 + y[i];
            if (cur / d || r) a[r++] = cur / d;
            cur %= d;
        }
        reverse (a, a + r);
        int tmp = 0, R = 0;
        while (tmp == 0 || tmp < 10 && R < p - 1) {
            tmp += b;
            R = max (R, r);
            int cur = 0;
            for (int i = 0; i < R; i++) {
                A[i] += a[i] + cur;
                cur = A[i] / 10;
                A[i] %= 10;
            }
            if (cur) A[R++] = cur % 10;
        }
        if (tmp < 10 && R == p - 1) {
            reverse (A, A + p - 1);
            for (int i = 0; i < p - 1; i++) printf ("%d", A[i]);
            printf ("%d\n", tmp);
        } else printf ("Impossible\n");
    } else printf ("Impossible\n");
    return 0;
}