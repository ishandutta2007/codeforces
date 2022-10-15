/// In The Name Of God

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

string s;

void change(string &x) {
	for (char &i : x) {
		if (isupper(i)) i += 32;
		if (i == 'i' || i == 'l') i = '1';
		if (i == 'o') i = '0';
	}
}
void check() {
	string t;
	cin >> t;
	change(t);
	if (s == t) cout << "No", ioi
}
int main() {
	#ifdef IOI2018
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> s;
	change(s);

	int n = 1;
	cin >> n;
	while (n--) {
		check();
	}
	cout << "Yes";
	ioi
}