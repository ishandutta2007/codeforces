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
string s, t;
int w[2][2];

int main () {
    cin >> n >> s >> t;
    for (int i = 0; i < 2 * n; i++) w[s[i] - '0'][t[i] - '0']++;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (w[1][1] > 0) {
            a++;
            w[1][1]--;
        } else
        if (w[1][0] > 0) {
            a++;
            w[1][0]--;
        } else
        if (w[0][1] > 0) {
            w[0][1]--;
        } else {
            w[0][0]--;
        }

        if (w[1][1] > 0) {
            b++;
            w[1][1]--;
        } else
        if (w[0][1] > 0) {
            b++;
            w[0][1]--;
        } else
        if (w[1][0] > 0) {
            w[1][0]--;
        } else {
            w[0][0]--;
        }
    }
    if (a > b) printf ("First\n"); else
    if (a < b) printf ("Second\n"); else printf ("Draw\n");

    return 0;
}