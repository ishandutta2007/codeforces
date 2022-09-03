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
int cnt[26];
string ans;

int go (int i, int f, string cur) {
    if (f == 1 || i == m) {
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < cnt[j]; k++)
                cur += char ('a' + j);
        if (cur > t) {
            ans = min (ans, cur);
            re 1;
        }   
        re 0;
    }
    for (int j = t[i] - 'a'; j < 26; j++)
        if (cnt[j] > 0) {
            cnt[j]--;
            if (go (i + 1, int (j > t[i] - 'a'), cur + char (j + 'a'))) re 1;
            cnt[j]++;
        }
    re 0;
}

int main () {
    cin >> s >> t;
    n = sz (s);
    m = sz (t);
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    ans = "{";
    go (0, 0, "");
    if (ans == "{") ans = "-1";
    cout << ans << endl;
    return 0;
}