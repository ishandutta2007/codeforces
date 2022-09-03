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

const int N = 200000;
 
int n;
int m;
string s;
int cnt[N + 1][17];
vi v[17][N + 1];
int res[1 << 17];

int cool (int h) {
	for (int i = 0; i < (1 << m); i++) res[i] = -1;
	res[0] = n;
	for (int i = 0; i < (1 << m); i++)
		if (res[i] >= h) {
			for (int j = 0; j < m; j++)
				if (((i >> j) & 1) == 0) {
					if (cnt[res[i] - h][j] >= h)
						res[i | (1 << j)] = max (res[i | (1 << j)], res[i] - h);
					else
					if (!v[j][h].empty () && v[j][h][0] <= res[i] - h) {
						int l = 0, r = sz (v[j][h]);
						while (r - l > 1) {
							int s = (l + r) / 2;
							if (v[j][h][s] <= res[i] - h) l = s; else r = s;
						}
						res[i | (1 << j)] = max (res[i | (1 << j)], v[j][h][l]);
					}
				}
		}
	re int (res[(1 << m) - 1] >= 0);
}

int main () {
    cin >> n >> m >> s;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            if (s[i] == '?' || s[i] - 'a' == j)
                cnt[i][j] = cnt[i + 1][j] + 1;
            else
            	cnt[i][j] = 0;
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		if (cnt[i][j] != 0) {
    			v[j][cnt[i][j]].pb (i);
//    			printf ("%d %d = %d\n", i, j, cnt[i][j]);
    		}	
    int l = 0, r = n + 1;
    while (r - l > 1) {
    	int s = (l + r) / 2;
    	if (cool (s)) l = s; else r = s;
    }
    printf ("%d\n", l);
    re 0;
}