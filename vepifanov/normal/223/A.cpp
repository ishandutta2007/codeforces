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
string s;
int h[100001];
int w[100001];
int v[100001];

int cool (char a, char b) {
    if (a == '(' && b == ')' || a == '[' && b == ']') re 1;
    re 0;
}

int main () {
    cin >> s;
    n = sz (s);
    h[n] = 0;
    w[n] = n;
    int r = 0;
    int ans = 0, last = n;
    int ri = 0, rj = 0;
    for (int i = n - 1; i >= 0; i--) {
        h[i] = h[i + 1] + int (s[i] == '[');
        w[i] = i;
        if (s[i] == ')' || s[i] == ']')
            v[r++] = i;
        else {
            if (r > 0 && cool (s[i], s[v[r - 1]]) && v[r - 1] < last) {
                w[i] = w[v[r - 1] + 1];
                if (h[i] - h[w[i]] > ans) {
                    ans = h[i] - h[w[i]];
                    ri = i;
                    rj = w[i];
                }
            } else last = i;
            r = max (r - 1, 0);
        }
    }
    cout << ans << endl << s.substr (ri, rj - ri) << endl;
    return 0;
}