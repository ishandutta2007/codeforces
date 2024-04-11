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

int main () {
    scanf ("%d", &n);
    int p0 = 0, p5 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        p0 += int (x == 0);
        p5 += int (x == 5);
    }
    if (p0 == 0) printf ("-1\n"); else {
        int a = (p5 / 9) * 9;
        int b = 1;
        if (a) b = p0;
        printf ("%s%s\n", string (a, '5').c_str (), string (b, '0').c_str ());
    }
    return 0;
}