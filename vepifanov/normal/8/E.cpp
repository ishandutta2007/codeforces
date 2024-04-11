#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
ll k;
int was[51][2][2];
ll res[51][2][2];

ll go (string s, int l, int r, int e, int er) {
    if (l > r) re 1;
    if (was[l][e][er]) re res[l][e][er];
    was[l][e][er] = 1;
    res[l][e][er] = 0;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            if ((s[l] == '?' || s[l] - '0' == a) && (s[r] == '?' || s[r] - '0' == b) && (l < r || a == b) && (!e || a <= b) && (!er || a <= 1 - b))
                res[l][e][er] += go (s, l + 1, r - 1, e & int (a == b), er & int (a == 1 - b));
    re res[l][e][er];
}                

int main() {
    cin >> n >> k;  
    k++;
    string s (n, '?');
    for (int i = 0; i < n; i++) {
        s[i] = '0';
        memset (was, 0, sizeof (was));
        ll t = go (s, 0, n - 1, 1, 1);
        if (t < k) { k -= t; s[i] = '1'; }
    }
    if (s[0] == '1') s = "-1";
    cout << s << endl;
    return 0;
}