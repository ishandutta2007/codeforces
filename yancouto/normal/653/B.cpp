#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
char o[256][256];
int n;
char s[100], s2[100];

int solve(int i) {
	if(i == n) {
		for(i = 0; i < n; i++) s2[i] = s[i];
		for(i = 0; i < n - 1; i++)
			if(!o[s2[i]][s2[i + 1]]) return 0;
			else
				s2[i + 1] = o[s2[i]][s2[i + 1]];				
		return s2[n - 1] == 'a';
	}
	int ans = 0;
	for(int j = 'a'; j <= 'f'; j++) {
		s[i] =  j;
		ans += solve(i + 1);
	}
	return ans;
}

int main() {
	int i, q; char c1, c2;
	scanf("%d %d", &n, &q);
	for(i = 0; i < q; i++) {
		scanf(" %c %c", &c1, &c2);
		scanf(" %c", &o[c1][c2]);
	}
	printf("%d\n", solve(0));
}