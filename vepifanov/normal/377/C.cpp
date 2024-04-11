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
string s[20];
int t[20];
int x[100];
int was[1 << 20];
int res[1 << 20];

int go (int mask) {
    int i = 0;
    for (int k = 0; k < m; k++)
        if ((mask >> k) & 1)
            i++;
    if (i == m) re 0;
    if (was[mask]) re res[mask];
    was[mask] = 1;
    int ans = (int (t[i] == 2) - int (t[i] == 1)) * 1e9;
    for (int k = 0; k < m; k++)
        if (((mask >> k) & 1) == 0)
            if (t[i] == 1) {
                if (s[i] == "p") 
                    ans = max (ans, go (mask | (1 << k)) + x[k]);
                else
                    ans = max (ans, go (mask | (1 << k)));  
            } else {
                if (s[i] == "p")
                    ans = min (ans, go (mask | (1 << k)) - x[k]);
                else
                    ans = min (ans, go (mask | (1 << k)));  
            }
    re res[mask] = ans;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort (x, x + n);
    reverse (x, x + n);
    cin >> m;
    for (int i = 0; i < m; i++) cin >> s[i] >> t[i];
    printf ("%d\n", go (0));
    return 0;
}