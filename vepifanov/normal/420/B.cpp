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
string s[100000];
int x[100000];
int bad[100001];
int now[100001];
int was[100001];
int use[100001];

int check (int low, int x) {
    int r = low;
    int now = use[x];
    for (int i = 0; i < m; i++) {
        if (s[i] == "+") {
            r++;
            now += int (::x[i] == x);
        } else {
            r--;
            now -= int (::x[i] == x);
        }
        if (r > 0 && !now) re 0;
    }
    re 1;
}

int main () {
    cin >> n >> m;
    int low = 0;
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> x[i];
        was[x[i]] = 1;
        if (s[i] == "+") now[x[i]]++; else {
            if (now[x[i]] == 0) {
                use[x[i]] = 1;
                low++;
            } else
                now[x[i]]--;
        }
    }
    int r = low;
    for (int i = 0; i < m; i++) {
        if (s[i] == "+" && r >= 1 || s[i] == "-" && r > 1) bad[x[i]] = 1;
        r += int (s[i] == "+") - int (s[i] == "-");
    }
    if (low)
        for (int i = 1; i <= n; i++)
            if (!bad[i] && !use[i] && was[i])
                bad[i] = 1;
    int rem = 0;
    for (int i = 1; i <= n && rem <= 1; i++)
        if (was[i] && !bad[i]) {
            if (!check (low, i))
                bad[i] = 1;
            else
                rem++;
        }
    if (rem > 1) printf ("0\n"); else {
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += 1 - bad[i];
        printf ("%d\n", ans);
        for (int i = 1; i <= n; i++)
            if (!bad[i])
                printf ("%d ", i);
        printf ("\n");
    }
    return 0;
}