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
char s[100009];
int p[256];

int main() {
	int i, j, n, k; char c1, c2;
	scanf("%s", s); n = strlen(s);
	scanf("%d", &k);
	for(i = 0; i < k; i++) {
		scanf(" %c %c", &c1, &c2);
		p[c1] = c2; p[c2] = c1;
	}
	int tot = 0;
	for(i = 0; i < n; ) {
		if(!p[s[i]]) { i++; continue; }
		j = i + 1;
		int c[2] = {1, 0};
		while(j < n && (s[j] == s[i] || s[j] == p[s[i]])) c[s[j++] != s[i]]++;
		tot += min(c[0], c[1]);
		i = j;
	}
	printf("%d\n", tot);

}