// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int inf = 1e9 + 100;

int n;
int m;
int cnt[26];

int main () {
    int tt;
    cin >> tt;
    for (int it = 0; it < tt; it++) {
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < 26; i++) cnt[i] = 0;
        for (int i = 0; i < sz (t); i++) cnt[t[i] - 'A']++;
        string ss = "";
        for (int i = sz (s) - 1; i >= 0; i--)
            if (cnt[s[i] - 'A'] > 0) {
                ss += s[i];
                cnt[s[i] - 'A']--;
            }
        reverse (all (ss));
        printf ("%s\n", ss == t ? "YES" : "NO");
    }
    re 0;
}