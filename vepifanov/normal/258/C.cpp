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

const int mod = 1000000000 + 7;

int n;
int m;
int c[100001];
int q[1000];

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        c[x]++;
    }
    for (int i = 99999; i >= 1; i--) c[i] += c[i + 1];
    int ans = 1;
    for (int i = 2; i <= 100000 && c[i]; i++) {
        int k = 0;
        for (int j = 1; j * j <= i; j++)
            if (i % j == 0) {
                q[k++] = c[j];
                if (j * j != i) q[k++] = c[i / j];
            }
        sort (q, q + k);
        reverse (q, q + k);
        q[k] = 0;
        int cur = 1;
        for (int j = k - 1; j >= 0; j--) cur = ((ll)cur * power (j + 1, q[j] - q[j + 1])) % mod;
        int tmp = 1;                                                                    
        k--;
        q[k] = 0;
        for (int j = k - 1; j >= 0; j--) tmp = ((ll)tmp * power (j + 1, q[j] - q[j + 1])) % mod;
        cur = (cur - tmp + mod) % mod;
        ans = (ans + cur) % mod;
    }       
    printf ("%d\n", ans);
    return 0;
}