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
string s, t;
int l1[1001], l2[1001], p[1000];

int gp () {
    p[0] = -1;
    for (int i = 1; i < m; i++) {
        int k = p[i - 1];
        while (k != -1 && t[k + 1] != t[i]) k = p[k];
        if (t[k + 1] == t[i]) k++;
        p[i] = k;
    }
    re 0;
}

int main () {
    int tt;
    cin >> s >> tt;
    n = sz (s);
    int ans = 0;
    for (int i = 0; i < tt; i++) {
        cin >> t;
        m = sz (t);
        gp ();
        for (int j = 1; j <= m; j++) l1[j] = l2[j] = n + 1;
        int k;
        k = -1;
        for (int j = 0; j < n; j++) {
            while (k != -1 && s[j] != t[k + 1]) k = p[k];
            if (s[j] == t[k + 1]) k++;
            if (l1[k + 1] > j) l1[k + 1] = j + 1;
            if (k + 1 == m) {
                break;
            }
        }
        reverse (all (t));
        gp ();
        k = -1;
        for (int j = 0; j < n; j++) {
            while (k != -1 && s[n - j - 1] != t[k + 1]) k = p[k];
            if (s[n - j - 1] == t[k + 1]) k++;
            if (l2[k + 1] > j) l2[k + 1] = j + 1;
            if (k + 1 == m) {
                break;
            }
        }
        for (int j = 1; j < m; j++)
            if (l1[j] + l2[m - j] <= n) {
                ans++;
                break;
            }   
    }
    printf ("%d\n", ans);
    return 0;
}