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

char s[2009];
int main() {
	int i, j, n;
	scanf("%d", &n);
	scanf("%s", s);
	int tot = 0;
	for(i = 0; i < n; i++) {
		int ci = 0, cj = 0;
		for(j = i; j < n; j++) {
			if(s[j] == 'U') ci--;
			else if(s[j] == 'D') ci++;
			else if(s[j] == 'L') cj--;
			else if(s[j] == 'R') cj++;
			if(!ci && !cj) tot++;
		}
	}
	printf("%d\n", tot);
}