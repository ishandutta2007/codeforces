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
int a, b;
map<ii, int> all;

int go (int a, int b) {
    if (a == b) re 0;
    if (a > b) swap (a, b);
    if (all.find (mp (a, b)) != all.end ()) re all[mp (a, b)];
    int ans = 1e9;
    if (a % 2 == 0) ans = min (ans, go (a / 2, b) + 1);
    if (a % 3 == 0) ans = min (ans, go (a / 3, b) + 1);
    if (a % 5 == 0) ans = min (ans, go (a / 5, b) + 1);
    if (b % 2 == 0) ans = min (ans, go (b / 2, a) + 1);
    if (b % 3 == 0) ans = min (ans, go (b / 3, a) + 1);
    if (b % 5 == 0) ans = min (ans, go (b / 5, a) + 1);
    re all[mp (a, b)] = ans;
}

int main () {
    cin >> a >> b;
    int tmp = go (a, b);
    cout << (tmp > 1e8 ? -1 : tmp) << endl;
    return 0;
}