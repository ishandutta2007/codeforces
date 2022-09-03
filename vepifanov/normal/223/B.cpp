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
int p[200000];
int q[200000];
int cnt[200001][26];

int main () {
    cin >> s >> t;
    n = sz (s);
    m = sz (t);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++)
            cnt[i][j] = cnt[i + 1][j];
        cnt[i][t[i] - 'a']++;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && s[i] == t[j]) j++;
        p[i] = j;
    }
    j = m;
    for (int i = n - 1; i >= 0; i--) {
        if (j > 0 && s[i] == t[j - 1]) j--;
        q[i] = j;
    }
    for (int i = 0; i < n; i++)
        if (cnt[q[i]][s[i] - 'a'] - cnt[p[i]][s[i] - 'a'] <= 0) {
            printf ("No\n");
            re 0;
        }
    printf ("Yes\n");
    return 0;
}