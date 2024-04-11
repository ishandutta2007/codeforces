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
int a[100000];

int prime (int x) {
    for (int i = 3; i * i <= x; i++)
        if (x % i == 0)
            re 0;
    re int (x > 1);
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    for (int i = 3; i <= n; i++)
        if (n % i == 0 && prime (i)) {
            int j = n / i;
            for (int k = 0; k < j; k++) {
                int ok = 1;
                for (int l = 0; l < i && ok; l++) ok &= a[k + l * j];
                if (ok) {
                    printf ("YES\n");
                    re 0;
                }
            }
        }
    printf ("NO\n");
    return 0;
}