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
int was[200];
int use[100001];
int g[100001];

int main() {
    scanf ("%d", &n);
    g[0] = 0;
    for (int i = 1; i <= n; i++) {
        use[i] = -1;
        for (int k = 500; k > 1; k--)
            if ((2 * i) % k == 0 && ((2 * i) / k - k + 1) % 2 == 0) {
                int j = ((2 * i) / k - k + 1) / 2;
                if (j <= 0) continue;
                int tmp = 0;
                for (int l = 0; l < k; l++) tmp ^= g[j + l];
                if (tmp == 0) use[i] = k;
                was[tmp] = i;
            }   
        int j = 0;
        while (was[j] == i) j++;
        g[i] = j;
    }
    printf ("%d\n", use[n]);
    return 0;
}