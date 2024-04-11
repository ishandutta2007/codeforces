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
int m, t;
deque<int> q;
vs res[100];
int a[200], b[200], d[100][100], x[100];
string s[100];

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> a[i + n] >> b[i + n];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> x[i];
        q.push_back (i);
    }
    int i = 0;
    int ct = t;
    while (!q.empty ()) {
        int j = i % n;
        if (i == j) j += n;
        int k = q.front ();
        q.pop_front ();
        int u = max (1, x[k] - (a[i] + b[j]) - d[i % n][k]);
        if (ct >= u) {
            ct -= u;
            res[i % n].pb (s[k]);
        } else {
            q.push_back (k);
            d[i % n][k] += ct;
            ct = 0;
        }
        if (ct == 0) {
            i = (i + 1) % (2 * n);
            ct = t;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sz (res[i]);
        for (int j = 0; j < sz (res[i]); j++)
            cout << " " << res[i][j];
        cout << "\n";
    }   
    re 0;
}