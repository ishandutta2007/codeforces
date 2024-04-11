#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
 
int n;
int m;
char h[100010];
string s[100010];
string t[100010];
int cnt[100010][26];

int main () {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d%d", &n, &m);
        for (int i = 0; i < m; i++) memset (cnt[i], 0, sizeof (cnt[i]));
        for (int i = 0; i < n; i++) {
            scanf (" %s", h);
            for (int j = 0; j < m; j++) cnt[j][h[j] - 'a']++;
        }
        for (int i = 0; i < n - 1; i++) {
            scanf (" %s", h);
            for (int j = 0; j < m; j++) cnt[j][h[j] - 'a']--;
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < 26; j++)
                if (cnt[i][j])
                    printf ("%c", j + 'a');
        printf ("\n");
        fflush (stdout);
    }
    re 0;
}