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

int calc (int x) {
    int y = 0;
    while (x) {
        y += x & 1;
        x /= 2;
    }
    re y;
}

int go (ll x, int mask) {
    if (x > n || calc (mask) > 2) re 0;
    int tmp = 1;
    for (int j = int (x == 0); j < 10; j++) tmp += go (x * 10 + j, mask | (1 << j));
    re tmp;
}

int main () {
    scanf ("%d", &n);
    printf ("%d\n", go (0, 0) - 1);
    return 0;
}