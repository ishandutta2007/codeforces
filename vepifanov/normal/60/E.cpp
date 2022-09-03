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
ll x, y;
int p;

int power (int a, ll b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % p;
        a = ((ll)a * a) % p;
        b /= 2;
    }
    re c;
}

int get3 (ll b) {
    if (b == 0) re 0;
    if (b == 1) re 1;
    if (b & 1) {
        int x = get3 (b - 1);
        re ((ll)3 * x + 1) % p;
    } else {
        int x = get3 (b / 2);
        re ((ll)2 * x * (x + 1)) % p;
    }
}

int e[2][2], g[2][2], w[2][2];
int a[1000000];

ii fib (ll b) {
    e[0][0] = e[1][1] = 1;
    e[0][1] = e[1][0] = 0;
    g[0][0] = g[1][0] = g[0][1] = 1;
    g[1][1] = 0;
    while (b) {
        if (b & 1) {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++) {
                    w[i][j] = 0;
                    for (int k = 0; k < 2; k++)
                        w[i][j] = (w[i][j] + (ll)e[i][k] * g[k][j]) % p;
                }
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    e[i][j] = w[i][j];  
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                w[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    w[i][j] = (w[i][j] + (ll)g[i][k] * g[k][j]) % p;
            }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                g[i][j] = w[i][j];  
        b /= 2;
    }
    re mp (e[0][0], e[0][1]);
}

int main() {
    cin >> n >> x >> y >> p;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
        sum = (sum + a[i]) % p;
    }   
        
    if (n == 1) {
        cout << sum % p << endl;
        re 0;
    }


    int ans = (((ll)power (3, x) * sum) % p - ((ll)get3 (x) * (a[0] + a[n - 1])) % p + p) % p;

    ii tmp = fib (x);

    int A = a[0];
    int B = ((ll)a[n - 1] * tmp.fi + (ll)a[n - 2] * tmp.se) % p;

    ans = (((ll)power (3, y) * ans) % p - ((ll)get3 (y) * (A + B)) % p + p) % p;

    cout << ans << endl;

    return 0;
}