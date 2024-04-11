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
const int N = 2000009;
int a[1009];
int dv[N];

int main() {
	int i, j, n;
	for(i = 2; i * i < N; i++)
		if(!dv[i])
			for(j = i * i; j < N; j += i)
				dv[j] = i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	vector<int> ans;
	if(n > 1 && a[1] == 1) {
		for(i = 0; i < n && a[i] == 1; i++)
			ans.pb(1);
		for(; i < n; i++)
			if(!dv[a[i] + 1])
				break;
		if(i < n) ans.pb(a[i]);
	} else {
		for(i = 0; i < n && ans.empty(); i++)
			for(j = i + 1; j < n && ans.empty(); j++) 
				if(!dv[a[i] + a[j]])
					ans.pb(a[i]), ans.pb(a[j]);
		if(ans.empty()) ans.pb(a[0]);
	}
	printf("%d\n", (int) ans.size());
	for(int x : ans)
		printf("%d ", x);
	putchar('\n');
}