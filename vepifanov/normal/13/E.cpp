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

const int LEN = 300;

int n;
int m;
int q[100000], l[100000], nf[100000], nc[100000];

int main() {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i < n; i++) scanf ("%d", &l[i]);
    for (int i = 0; i < n; i++) q[i] = i / LEN;
    for (int i = n - 1; i >= 0; i--)
        if (i + l[i] >= n) {
            nf[i] = n;
            nc[i] = 1;
        } else
        if (q[i + l[i]] != q[i] || (i + l[i] + l[i + l[i]] >= n || q[i + l[i] + l[i + l[i]]] != q[i])) {
            nf[i] = i + l[i];
            nc[i] = 1;
        } else
        if (q[i + l[i]] == q[i]) {
            nf[i] = nf[i + l[i]];
            nc[i] = nc[i + l[i]] + 1;
        }
    for (int i = 0; i < m; i++) {
        int t, a, b, c = 0;
        scanf ("%d%d", &t, &a); a--;
        if (t == 1) {
            while (a < n) {
                b = a;
                c += nc[a];
                a = nf[a];
            }
            printf ("%d %d\n", b + 1, c);
        } else {
            scanf ("%d", &b);
            l[a] = b;
            for (int j = a; j >= 0 && q[j] == q[a]; j--)
                if (j + l[j] >= n) {
                    nf[j] = n;
                    nc[j] = 1;
                } else
                if (q[j + l[j]] != q[j] || (j + l[j] + l[j + l[j]] >= n || q[j + l[j] + l[j + l[j]]] != q[j])) {
                    nf[j] = j + l[j];
                    nc[j] = 1;
                } else
                if (q[j + l[j]] == q[j]) {
                    nf[j] = nf[j + l[j]];
                    nc[j] = nc[j + l[j]] + 1;
                }
        }
    }
    return 0;
}