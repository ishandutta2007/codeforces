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

const int p10[6] = {1, 10, 100, 1000, 10000, 100000};

int n;
int m;

int prime (int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            re 0;
    re 1;
}

int g[5];
int pr[100000];

int add (int i, int x) {
    for (int j = i; j < n; j++)
        if (j == i) g[j] = x; else g[j] = g[j] * 10 + (x / p10[n - j - 1]) % 10;
    re 0;
}

int del (int i) {
    for (int j = i; j < n; j++)
        if (j == i) g[j] /= p10[n - i]; else g[j] /= 10;
    re 0;
}

int all[5][10000][1240];
int cnt[5][10000];

int go (int i) {
    if (i == n - 1) re cnt[n - 1][g[n - 1]];
    for (int j = i; j < n; j++)
        if (!cnt[i][g[j]])
            re 0;
    int ans = 0;
    int og[5];
    for (int j = 0; j < n; j++) og[j] = g[j];
    for (int j = 0; j < cnt[i][g[i]]; j++) {
        add (i, all[i][g[i]][j]);
        ans += go (i + 1);
        for (int k = i; k < n; k++) g[k] = og[k];
    }
    re ans;
}

int main () {
    int tt;
    cin >> tt;
    for (int i = 0; i < 100000; i++) pr[i] = prime (i);
    for (int it = 0; it < tt; it++) {
        string s;
        cin >> s;
        n = sz (s);
        memset (cnt, 0, sizeof (cnt));
        for (int i = 2; i < p10[n]; i++)
            if (pr[i])
                for (int j = 1; j < n; j++) {
                    int k = i / p10[n - j];
                    all[j][k][cnt[j][k]] = i;
                    cnt[j][k]++;
                }   
        for (int i = 0; i < n; i++) g[i] = 0;
        int x = 0;
        for (int i = 0; i < sz (s); i++) x = x * 10 + s[i] - '0';
        add (0, x);
        printf ("%d\n", go (1));
    }
    return 0;
}