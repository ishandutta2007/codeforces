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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
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
string s[100];
int t[100];
int now[1000001];

int main () {
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        if (s[i] == "+") now[t[i]] = 1; else {
            if (!now[t[i]]) cur++;
            now[t[i]] = 0;
        }
    }
    int ans = cur;
    for (int i = 0; i < n; i++) {
        cur += int (s[i] == "+") - int (s[i] == "-");
        ans = max (ans, cur);
    }
    cout << ans << endl;
    return 0;
}