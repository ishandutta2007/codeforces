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

string s;

vi v, w[26];
ll cnt[26];

int main () {
    cin >> s >> m;
    n = sz (s);
    if ((ll)n * (n + 1) / 2 < m) {
        cout << "No such line." << endl;
        re 0;
    }
    for (int i = 0; i < n; i++) v.pb (i);
    string cur = "";
    while (true) {
        for (int j = 0; j < 26; j++) {
            w[j].clear ();
            cnt[j] = 0;
        }   
        if (cur != "") m -= sz (v);
        if (m <= 0) {
            cout << cur << endl;
            break;
        }
        for (int j = 0; j < sz (v); j++)
            if (v[j] != n) {
                w[s[v[j]] - 'a'].pb (v[j] + 1);
                cnt[s[v[j]] - 'a'] += n - v[j];
            }   
        for (int j = 0; j < 26; j++)
            if (m <= cnt[j]) {
                v = w[j];
                cur += char ('a' + j);
                break;
            } else m -= cnt[j];
    }
    return 0;
}