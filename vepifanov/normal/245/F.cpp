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

const int ms[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
int m;

char h[5000001];
int x[5000000];

int main () {
    scanf ("%d%d", &n, &m);
    gets (h);
    int i = 0;
    while (gets (h)) {
        if (!h[0]) break;
        int m1 = (h[5] - '0') * 10 + (h[6] - '0');
        int d1 = (h[8] - '0') * 10 + (h[9] - '0');
        int h2 = (h[11] - '0') * 10 + (h[12] - '0');
        int m2 = (h[14] - '0') * 10 + (h[15] - '0');
        int s2 = (h[17] - '0') * 10 + (h[18] - '0');
        int p = 0;
        for (int j = 1; j < m1; j++) p += ms[j] * 86400;
        p += (d1 - 1) * 86400;
        p += h2 * 3600 + m2 * 60 + s2;
        x[i++] = p;
        if (i - m >= 0 && p - x[i - m] < n) {
            printf ("2012-%02d-%02d %02d:%02d:%02d\n", m1, d1, h2, m2, s2);
            re 0;
        }
    }
    printf ("-1\n");
    return 0;
}