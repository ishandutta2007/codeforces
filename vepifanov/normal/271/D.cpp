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
int w[26];
string s, t;
int r = 1;
int next[1500 * 1500][26];

int main () {
    cin >> s >> t >> m;
    for (int i = 0; i < 26; i++) w[i] = t[i] - '0';
    n = sz (s);
    for (int i = 0; i < n; i++) {
        int cnt = 0, x = 0;
        for (int j = i; j < n; j++) {
            cnt += 1 - w[s[j] - 'a'];
            if (cnt > m) break;
            if (next[x][s[j] - 'a'] == 0) next[x][s[j] - 'a'] = r++;
            x = next[x][s[j] - 'a'];
        }
    }
    cout << r - 1 << endl;
    return 0;
}