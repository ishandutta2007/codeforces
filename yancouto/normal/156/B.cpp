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

int a[100009], b[100009];
int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(a[i] > 0) b[a[i]]++, b[a[i]+1]--;
		else { b[0]++; b[-a[i]]--; b[-a[i]+1]++; }
	}
	int pos = 0;
	for(i = 1; i <= n; i++) {
		b[i] += b[i-1];
		if(b[i] == m) pos++;
	}
	for(i = 0; i < n; i++) {
		if(a[i] > 0) {
			if(b[a[i]] == m && pos == 1) puts("Truth");
			else if(b[a[i]] == m) puts("Not defined");
			else puts("Lie");
		} else {
			if(b[-a[i]] == m && pos == 1) puts("Lie");
			else if(b[-a[i]] == m) puts("Not defined");
			else puts("Truth");
		}
	}
}