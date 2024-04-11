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

const int mps[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
int m;
string s, t;

int vis (int x) { re (x % 400 == 0 || x % 100 != 0 && x % 4 == 0); }

int main () {
    cin >> s >> t;
    if (s > t) swap (s, t);
    int y1 = (((s[0] - '0') * 10 + s[1] - '0') * 10 + s[2] - '0') * 10 + s[3] - '0';
    int m1 = (s[5] - '0') * 10 + s[6] - '0';
    int d1 = (s[8] - '0') * 10 + s[9] - '0';
    int y2 = (((t[0] - '0') * 10 + t[1] - '0') * 10 + t[2] - '0') * 10 + t[3] - '0';
    int m2 = (t[5] - '0') * 10 + t[6] - '0';
    int d2 = (t[8] - '0') * 10 + t[9] - '0';
    int ans = 0;
    while (y1 != y2 || d1 != d2 || m1 != m2) {
        ans++;
        d1++;
        if (d1 > mps[m1] + int (m1 == 2) * vis (y1)) {
            d1 = 1;
            m1++;
            if (m1 == 13) {
                m1 = 1;
                y1++;
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}