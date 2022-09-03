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
vi x, y;
string s;

int main () {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        x.pb (s[i] - '0');
        y.pb (s[i + n] - '0');
    }   
    sort (all (x));
    sort (all (y));
    int ok1 = 1, ok2 = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] >= y[i]) ok1 = 0;
        if (x[i] <= y[i]) ok2 = 0;
    }
    if (ok1 || ok2) printf ("YES\n"); else printf ("NO\n");
    return 0;
}