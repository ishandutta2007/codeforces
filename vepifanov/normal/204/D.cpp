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

int rb[1000001], rw[1000001];
string s;

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
    scanf ("%d%d", &n, &m);
    cin >> s;
    int cur = 0, cnt = 0, all = 0, all2 = 0;
    for (int i = 0; i < n; i++) {
        if (i - m >= 0 && s[i - m] == 'X') {
            cnt++;
            all2 = (all2 * 2) % mod;
        }   
        if (s[i] == 'W') cur = 0; else cur++;
        if (cur >= m) {
            int tmp = power (2, cnt);
            rb[i] = ((ll)tmp - all - all2 + 2 * mod) % mod;
        }
        all = (all + rb[i]) % mod;
        if (i - m >= 0) {
            all = (all - rb[i - m] + mod) % mod;
            all2 = (all2 + rb[i - m]) % mod;
        }
    }
    cur = cnt = all = all2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i + m < n && s[i + m] == 'X') {
            cnt++;
            all2 = (all2 * 2) % mod;
        }   
        if (s[i] == 'B') cur = 0; else cur++;
        if (cur >= m) {
            int tmp = power (2, cnt);
            rw[i] = ((ll)tmp - all - all2 + 2 * mod) % mod;
        }
        all = (all + rw[i]) % mod;
        if (i + m < n) {
            all = (all - rw[i + m] + mod) % mod;
            all2 = (all2 + rw[i + m]) % mod;
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
//      printf ("%d %d\n", rb[i], rw[i]);
        ans = (ans + (ll)sum * rw[i]) % mod;
        if (s[i] == 'X') sum = (2 * sum) % mod;
        sum = (sum + rb[i]) % mod;
    }
    printf ("%d\n", ans);
    return 0;
}