#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 5;

int n;
unsigned int ans[maxn];
unsigned int a[maxn];
unsigned int f[maxn], g[maxn];

int main(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%u", a + i);
	FOR(i, 0, n){
		if(!i)
			f[i] = (~a[i]);
		else
			f[i] = f[i - 1] & (~a[i]);
	}
	for(int i = n - 1; i >= 0; --i){
		if(i == n - 1)
			g[i] = (~a[i]);
		else
			g[i] = g[i + 1] & (~a[i]);
	}
	FOR(i, 0, n){
		unsigned int vl = (!i ? (~0u) : f[i - 1]),
			vr = (i == n - 1 ? (~0u) : g[i + 1]);
		ans[i] = (a[i] & vl & vr);
	}
	int pos = 0;
	FOR(i, 0, n) if(ans[pos] < ans[i])
		pos = i;
	printf("%u ", a[pos]);
	FOR(i, 0, pos)
		printf("%u ", a[i]);
	for(int i = pos + 1; i < n; ++i)
		printf("%u ", a[i]);
	puts("");
	return 0;
}