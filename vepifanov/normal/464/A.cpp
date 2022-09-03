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
#define prev PREV
                         
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
int x[1000];

int add (int h) {
    int r = 1;
    for (int i = h + 1; i < n; i++) x[i] = 0;
    for (int i = h; i >= 0; i--) {
        r += x[i];
        x[i] = r % m;
        r /= m;
    }
    if (r) re 1;
    re 0;
}

int main () {
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; i++) x[i] = s[i] - 'a';
    if (add (n - 1)) {
        printf ("NO\n");
        re 0;
    }
    while (true) {
        int pos = n;
        for (int i = 0; i < n; i++) {
            if (i > 0 && x[i] == x[i - 1]) {
                pos = i;
                break;
            }
            if (i > 1 && x[i] == x[i - 2]) {
                pos = i;
                break;
            }
        }
        if (pos == n) break;
        if (add (pos)) {
            printf ("NO\n");
            re 0;
        }
    }
    for (int i = 0; i < n; i++) printf ("%c", char ('a' + x[i]));
    return 0;
}