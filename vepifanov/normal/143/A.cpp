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

int r1, r2, c1, c2, d1, d2;

int main () {
    scanf ("%d%d%d%d%d%d", &r1, &r2, &c1, &c2, &d1, &d2);
    for (int a = 1; a <= 9; a++)
        for (int b = 1; b <= 9; b++)
            if (a != b)
                for (int c = 1; c <= 9; c++)
                    if (a != c && b != c)
                        for (int d = 1; d <= 9; d++)
                            if (a != d && b != d && c != d)
                                if (a + b == r1 && c + d == r2 && a + c == c1 && b + d == c2 && a + d == d1 && b + c == d2) {
                                    printf ("%d %d\n%d %d\n", a, b, c, d);
                                    re 0;
                                }
    printf ("-1\n");
    return 0;
}