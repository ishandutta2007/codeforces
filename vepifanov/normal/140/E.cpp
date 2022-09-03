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
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

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


int n, m, p;
int l[1000000];
int res[20000001];
int g[1000000];
int A[5001];
int f[5001];

int cnt[5001][5001];

int main() {
        scanf ("%d%d%d", &n, &m, &p);
        A[0] = 1;
        f[0] = 1;
        for (int i = 1; i <= 5000; i++) {
                A[i] = ((ll)A[i - 1] * (m - i + 1)) % p;
                f[i] = ((ll)f[i - 1] * i) % p;
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
                scanf ("%d", &l[i]);
                g[i] = tmp;
                tmp += l[i] + 1;
        }
        memset (cnt, 0, sizeof (cnt));
        cnt[1][1] = 1;
        for (int i = 2; i <= 5000; i++)
                for (int j = 2; j <= 5000; j++)
                        cnt[i][j] = (cnt[i - 1][j - 1] + (ll)cnt[i - 1][j] * (j - 1)) % p;
        int sum = 1;
        for (int i = 0; i < n; i++) {
                int nsum = 0;
                for (int j = 1; j <= l[i]; j++) {
                        res[g[i] + j] = (((ll)sum * cnt[l[i]][j]) % p * A[j]) % p;
                        if (i > 0 && j <= l[i - 1]) {
                                int tmp2 = (((ll)res[g[i - 1] + j] * cnt[l[i]][j]) % p * f[j]) % p;
                                res[g[i] + j] = (res[g[i] + j] - tmp2 + p) % p;
                        }
                        (nsum += res[g[i] + j]) %= p;
                }
                sum = nsum;
        }
        printf ("%d\n", sum % p);
        return 0;
}