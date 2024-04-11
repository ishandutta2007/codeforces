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
int q[100];
int was[100];
int s[100];
int p[100];
int t[100];

int gcd (int a, int b) {
    re a ? gcd (b % a, a) : b;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &q[i]);
        q[i]--;
    }   
    for (int i = 0; i < n; i++) {
        scanf ("%d", &s[i]);
        s[i]--;
    }
    int len = 1;
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            int k = 0, j = i;
            while (!was[j]) {
                was[j] = 1;
                k++;
                j = q[j];
            }
            len = len / gcd (len, k) * k;
        }
    for (int i = 0; i < n; i++) p[i] = i;
    int pa = -len, pb = len;
    for (int i = 0; i <= m; i++) {
        int ok = 1;
        for (int j = 0; j < n; j++)
            if (p[j] != s[j])
                ok = 0;
        if (ok) {
            pb = i;
            break;
        }
        for (int j = 0; j < n; j++) t[j] = p[q[j]];
        for (int j = 0; j < n; j++) p[j] = t[j];
    }
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i <= m; i++) {
        int ok = 1;
        for (int j = 0; j < n; j++)
            if (p[j] != s[j])
                ok = 0;
        if (ok) {
            pa = -i;
            break;
        }
        for (int j = 0; j < n; j++) t[q[j]] = p[j];
        for (int j = 0; j < n; j++) p[j] = t[j];
    }
    if (pa == -len && pb == len) {
        printf ("NO\n");
        re 0;
    }
    if (pa == -len) pa = pb - len;
    if (pb == len) pb = pa + len;
    if (pb % 2 == m % 2 && pb <= m) {
        if (pb == m || pb - pa > 2) {
            printf ("YES\n");
            re 0;
        }
    }
    if ((-pa) % 2 == m % 2 && (-pa) <= m) {
        if (-pa == m || pb - pa > 2) {
            printf ("YES\n");
            re 0;
        }
    }
    printf ("NO\n");
    return 0;
}