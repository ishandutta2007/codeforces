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

const int N = 40000;

int n;
int m;
string s;

int cnt[N];

int main () {
    cin >> m >> s;
    n = sz (s);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i; j < n; j++) {
            cur += s[j] - '0';
            cnt[cur]++;
        }
    }
    ll ans = 0;
    if (m == 0) {
        int all = n * (n + 1) / 2;
        ans += (ll)all * all - (ll)(all - cnt[0]) * (all - cnt[0]);
    } else {
        for (int i = 1; i * i <= m && i < N; i++)
            if (m % i == 0 && m / i < N) {
                int j = m / i;
                if (i != j) ans += (ll)2 * cnt[i] * cnt[j]; else ans += (ll)cnt[i] * cnt[i];
            }
    }
    cout << ans << endl;
    return 0;
}