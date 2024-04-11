#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int a[1000009];
int main() {
	int i, n, x; char c;
	scanf("%d", &n);
	int mxcp = 0, curcp = 0;
	for(i = 0; i < n; i++) {
		scanf(" %c %d", &c, &x);
		if(c == '+') {
			curcp++;
			a[x] = 1;
			mxcp = max(mxcp, curcp);
		} else {
			if(a[x]) { curcp--; a[x] = 0; }
			else {
				mxcp++;
			}
		}
	}
	printf("%d\n", mxcp);
	return 0;
}