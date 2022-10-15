#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define K 400001
#define LL long long
#define mp make_pair
#define pb push_back
#define M 1000000007
#define pow qjwopjqpw
 
 
int n, k;
int heav[K], b[K], a[K];
vector<int> v;
 
int main() {
	scanf("%d%d", &n, &k);
	
	FOE(i, 1, n) {
		scanf("%d", &a[i]);	
	}
	
	FOE(i, 1, n) {
		scanf("%d", &b[i]);	
		
		if (heav[a[i]] == 0 || b[heav[a[i]]] < b[i]) heav[a[i]] = i;
	}
	
	FOE(i, 1, n) if (heav[a[i]] != i) v.pb(b[i]);
	
	sort(v.begin(), v.end());
	
	int cnt = 0;
	FOE(i, 1, k) if (heav[i] == 0) cnt++;
	
	LL ret = 0;
	
	FOR(i, 0, cnt) ret += v[i];
	printf("%lld\n", ret);
}