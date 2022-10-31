#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINEJUDGE
#	define LLD "%I64d"
#	define debug(...) fprintf(stderr, ...)
#else
#	define LLD "%lld"
#	define debug(...) {}
#endif

string s;
set<string> mp;
int seen[10009][6];
void solve(int i, int pr) {
	if(i <= 5) return;
	if(seen[i][pr]) return;
	seen[i][pr] = 1;
	mp.insert(s.substr(i - 1, 2));
	if(pr != 2 || s.substr(i - 1, 2) != s.substr(i + 1, 2)) solve(i - 2, 2);
	if(i > 6) {
		mp.insert(s.substr(i - 2, 3));
		if(pr != 3 || s.substr(i - 2, 3) != s.substr(i + 1, 3)) solve(i - 3, 3);
	}
}

char ss[112345];
int main() {
	int i, j, n;
	scanf("%s", ss);
	s = ss;
	solve(s.size() - 1, 0);
	printf("%d\n", (int) mp.size());
	for(const string &s : mp)
		printf("%s\n", s.c_str());
}