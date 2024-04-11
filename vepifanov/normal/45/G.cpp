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

int n;
int m;
bool u[20000000];

int main() {
    u[0] = u[1] = 1;
    for (int i = 2; i < 20000000; i++)
        if (!u[i]) {
            if (i < 5000)
                for (int j = i * i; j < 20000000; j += i)
                    u[j] = 1;
        }
    scanf ("%d", &n);
    int s = n * (n + 1) / 2;
    if (!u[s]) {
        for (int i = 0; i < n; i++) printf ("1 ");
        printf ("\n");
        re 0;
    }
    for (int i = 2; i <= n; i++)
        if (!u[i] && !u[s - i]) {
            for (int j = 1; j <= n; j++) printf ("%d ", 1 + int (i == j));
            printf ("\n");
            re 0;
        }
    for (int i = 2; i < n; i++)
        if (!u[i])
            for (int j = i + 1; j <= n; j++)
                if (!u[j] && !u[s - i - j]) {
                    for (int k = 1; k <= n; k++) printf ("%d ", 1 + int (i == k) + 2 * int (j == k));
                    printf ("\n");
                    re 0;
                }
    return 0;
}