#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

const int mod = 1000*1000*1000+7;

int n;
int m;
int last[26];
int res[2000100];
int sum[2000100];
int k;
string s;

int main () {
	cin >> n >> k;
	cin >> s;
	n += sz (s);
	res[0] = 1;
	sum[1] = 1;
	for (int i = 1; i <= n; i++)
		if (i <= sz (s)) {
			res[i] = (sum[i] - sum[last[s[i - 1] - 'a']] + mod) % mod;
			sum[i + 1] = (sum[i] + res[i]) % mod;
			last[s[i - 1] - 'a'] = i;
		} else {
			int best = 0;
			for (int j = 0; j < k; j++)
				if (last[best] > last[j])
					best = j;
			res[i] = (sum[i] - sum[last[best]] + mod) % mod;
			sum[i + 1] = (sum[i] + res[i]) % mod;
			last[best] = i;
		}
	printf ("%d\n", sum[n + 1]);
	return 0;
}