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
#include <cassert>

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
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 200000;

int n;
int m;
int x[N + 1];
int y[N + 1];
string s, t;

int main () {
    cin >> s >> t;
    for (int i = 0; i < sz (s); i++)
        x[sz (s) - i - 1] = s[i] - '0';
    for (int i = 0; i < sz (t); i++)
        y[sz (t) - i - 1] = t[i] - '0';
    for (int i = 0; i < N; )
        if (x[i]) {
            int j = i;
            while (x[j]) j++;
            for (int k = j - 1; k > i; k -= 2) {
                x[k] = x[k - 1] = 0;
                x[k + 1] = 1;
            }
            i = j;
        } else i++;
    for (int i = 0; i < N; )
        if (y[i]) {
            int j = i;
            while (y[j]) j++;
            for (int k = j - 1; k > i; k -= 2) {
                y[k] = y[k - 1] = 0;
                y[k + 1] = 1;
            }
            i = j;
        } else i++;
    for (int i = N; i >= 0; i--)
        if (x[i] != y[i]) {
            printf ("%c\n", x[i] < y[i] ? '<' : '>');
            re 0;
        }
    printf ("=\n");
    return 0;
}