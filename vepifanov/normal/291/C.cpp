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
ll x[100000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf ("%d.%d.%d.%d", &a, &b, &c, &d);
        x[i] = (((ll)a * 256 + b) * 256 + c) * 256 + d;
    }
    sort (x, x + n);
    reverse (x, x + n);
    ll cur = 0;
    for (int i = 1; i <= 32; i++) {
        cur += (ll)1 << (32 - i);
        int tmp = 0;
        for (int j = 0; j < n; j++)
            if (j == 0 || (x[j] & cur) != (x[j - 1] & cur)) tmp++;
        if (tmp == m) {
            cout << ((cur >> 24) & 255) << "." << ((cur >> 16) & 255) << "." << ((cur >> 8) & 255) << "." << (cur & 255) << endl;
            re 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}