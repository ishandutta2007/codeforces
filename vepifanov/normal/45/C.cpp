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
string s;
int prev[200000], next[200000], x[200000];
set<ii> all;
vii ans;

int add (int a) {
    int b;
    b = prev[a];
    if (b != -1 && s[a] != s[b]) 
        all.insert (mp (abs (x[a] - x[b]), b));
    b = next[a];
    if (b != -1 && s[a] != s[b])
        all.insert (mp (abs (x[a] - x[b]), a));
    re 0;
}

int kill (int a) {
    int b;
    b = prev[a];
    if (b != -1 && s[a] != s[b]) 
        all.erase (mp (abs (x[a] - x[b]), b));
    b = next[a];
    if (b != -1 && s[a] != s[b])
        all.erase (mp (abs (x[a] - x[b]), a));
    re 0;
}

int main() {
    scanf ("%d" , &n);  
    cin >> s;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        if (i > 0) prev[i] = i - 1; else prev[i] = -1;
        if (i + 1 < n) next[i] = i + 1; else next[i] = -1;
    }
    for (int i = 0; i < n; i++)
        add (i);
    while (!all.empty ()) {
        int a = all.begin()->se;
        int b = next[a];
        int c = prev[a];
        int d = next[b];
        ans.pb (mp (a + 1, b + 1));
        kill (a);
        kill (b);
        if (c != -1) next[c] = d;
        if (d != -1) prev[d] = c;
        if (c != -1) add (c);
        if (d != -1) add (d);
    }
    printf ("%d\n", sz (ans));
    for (int i = 0; i < sz (ans); i++)
        printf ("%d %d\n", ans[i].fi, ans[i].se);
    return 0;
}