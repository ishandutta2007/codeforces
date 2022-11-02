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
bool only(char *s, char a, char b) {
	for(int i = 0; s[i]; i++)
		if(s[i] != a && s[i] != b)
			return false;
	return true;
}


char s[102][1003];

int main() {
	int i, j, k, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%s", s[i]);
	int mx = 0;
	for(i = 'a'; i <= 'z'; i++)
		for(j = i + 1; j <= 'z'; j++) {
			int tot = 0;
			for(k = 0; k < n; k++)
				if(only(s[k], i, j))
					tot += strlen(s[k]);
			mx = max(mx, tot);
		}
	printf("%d\n", mx);

}