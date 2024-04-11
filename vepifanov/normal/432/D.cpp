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

int n;
int m;
int p[100000];
vii res;
int cnt[100000];
string s;

int main () {
    cin >> s;
    n = sz (s);
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        int k = p[i - 1];
        while (k >= 0 && s[k + 1] != s[i]) k = p[k];
        if (s[k + 1] == s[i]) k++;
        p[i] = k;
    }
    for (int i = n - 1; i >= 0; i--) {
        cnt[i]++;
        if (p[i] != -1)
            cnt[p[i]] += cnt[i];
    }
    int k = n - 1;
    while (k >= 0) {
        res.pb (mp (k + 1, cnt[k]));
        k = p[k];
    }
    printf ("%d\n", sz (res));
    for (int i = sz (res) - 1; i >= 0; i--) printf ("%d %d\n", res[i].fi, res[i].se);
    return 0;
}