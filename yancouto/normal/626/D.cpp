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
const int N = 5009;
int dif[N], acc[N], a[N];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			dif[abs(a[i] - a[j])]++;
	for(i = 5002; i >= 0; i--)
		acc[i] = acc[i + 1] + dif[i];
	double all = (n * (n - 1)) / 2;
	double tot = 0;
	for(i = 1; i <= 5001; i++)
		if(dif[i])
			for(j = 1; j <= 5001; j++) {
				if(!dif[j] || i + j > 5001 || !acc[i + j + 1]) continue;
				tot += (dif[i] / all) * (dif[j] / all) * (acc[i + j + 1] / all);
			}
	printf("%.10f\n", tot);
}