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
int x[100000];
vi v[3];

int main () {
    scanf ("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        s += x[i];
    }
    sort (x, x + n);
    reverse (x, x + n);
    for (int i = n - 1; i >= 0; i--)
        v[x[i] % 3].pb (i);
    int ai = -1, bi = -1;
    if (s % 3 == 1) {   
        if (sz (v[1]) >= 1) ai = v[1][0]; else
        if (sz (v[2]) >= 2) { ai = v[2][0]; bi = v[2][1]; } else { printf ("-1\n"); re 0; }
    }
    if (s % 3 == 2) {
        if (sz (v[2]) >= 1) ai = v[2][0]; else
        if (sz (v[1]) >= 2) { ai = v[1][0]; bi = v[1][1]; } else { printf ("-1\n"); re 0; }
    }
    string res = "";
    for (int i = 0; i < n; i++) 
        if (i != ai && i != bi)
            res += char (x[i] + '0');
    if (res != "" && res[0] == '0') res = "0";
    if (res == "" || res[sz (res) - 1] != '0') printf ("-1\n"); else printf ("%s\n", res.c_str ());
    return 0;
}