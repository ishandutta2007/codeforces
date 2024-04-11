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
int was[100001][2][2];
int res[100001][2][2];
string s, t;

int go (int i, int a, int b) {
    if (i == n) re a * b;
    if (was[i][a][b]) re res[i][a][b];
    was[i][a][b] = 1;
    int cur = 0;
    for (int x = 0; x < 10; x++)
        for (int y = 0; y < 10; y++)
            if ((s[i] == '?' || s[i] - '0' == x) && (t[i] == '?' || t[i] - '0' == y))
                cur = (cur + go (i + 1, a | int (x > y), b | int (x < y))) % 1000000007;
    re res[i][a][b] = cur;
}

int main () {
    cin >> n >> s >> t;
    cout << go (0, 0, 0) << endl;
    return 0;
}