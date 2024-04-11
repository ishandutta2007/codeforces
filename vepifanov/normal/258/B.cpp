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
int was[10][2][10];
int res[10][2][10];
string s;
int cnt[10];
int ans[7][10];

int go (int i, int f, int k) {
    if (k < 0 || k > sz (s) - i) re 0;
    if (i == sz (s)) re 1;
    if (was[i][f][k]) re res[i][f][k];
    was[i][f][k] = 1;
    int cur = 0;
    for (int t = 0; t < 10; t++)
        if (f || s[i] - '0' >= t)
            cur += go (i + 1, f | int (s[i] - '0' > t), k - int (t == 4 || t == 7));
    re res[i][f][k] = cur;
}

int go2 (int i, int j) {
    if (i == 6) {
        int tmp = 0;
        for (int t = j + 1; t < 10; t++) tmp += cnt[t];
        re tmp;
    }
    int cur = 0;
    for (int t = 0; j + t < 10; t++) {
        cnt[t]--;
        cur = (cur + (ll)go2 (i + 1, j + t) * (cnt[t] + 1) % mod) % mod;
        cnt[t]++;
    }
    re cur;
}

int main () {
    cin >> s;
    for (int t = 0; t < 10; t++) cnt[t] = go (0, 0, t);
    cnt[0]--;
    cout << go2 (0, 0) << endl;
    return 0;
}