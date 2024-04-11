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
int m, k;
int a[1000], b[1000], use[1000];

int go (int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) printf ("%d ", a[j] + 1);
        printf ("\n");
        re 1;
    }
    for (int j = 0; j < n; j++)
        if (!use[j] && b[j] == 0) {
            a[i] = j;
            use[j] = 1;
            int ok = 1;
            for (int l = 0; l <= j - k; l++)
                if (!use[l]) {
                    b[l]--;
                    ok &= int (b[l] >= 0);
                }
            if (ok && go (i + 1)) re 1;
            for (int l = 0; l <= j - k; l++)
                if (!use[l]) {
                    b[l]++;
                    ok &= int (b[l] >= 0);
                }
        }
    re 0;
}

int main() {
    scanf ("%d%d", &n, &k); 
    for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
    go (0);
    return 0;
}