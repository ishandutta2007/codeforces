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
char s[200009];

int main() {
	char c;
	int i;
	scanf("%s", s);
	for(i = 1; s[i]; i++) {
		if(s[i] != s[i - 1]) continue;
		for(c = 'a'; c == s[i - 1] || c == s[i + 1]; c++);
		s[i] = c;
	}
	printf("%s\n", s);
}