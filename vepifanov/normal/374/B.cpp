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
string s;
ll cnt[100001];
int res[100001];

int main () {
    cin >> s;
    n = sz (s);
    res[n] = 0;
    cnt[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] = res[i + 1];
        cnt[i] = cnt[i + 1];
        if (i + 1 < n && s[i] - '0' + s[i + 1] - '0' == 9) {
            if (res[i + 2] + 1 > res[i]) {
                res[i] = res[i + 2] + 1;
                cnt[i] = cnt[i + 2];
            } else
            if (res[i + 2] + 1 == res[i])
                cnt[i] += cnt[i + 2];
        }
    }
    cout << cnt[0] << endl;
    return 0;
}