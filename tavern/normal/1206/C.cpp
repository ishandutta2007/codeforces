// orz dxm
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define y0 yORZDXM
#define y1 yORZDXM
#define y2 yORZDXM
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 5;

int n;
int ans[maxn << 1];

int main(){
	scanf("%d", &n);
	if(!(n & 1)){
		puts("NO");
		return 0;
	}
	puts("YES");
	FOR(i, 0, n){
		if(!(i & 1))
			ans[i] = i << 1 | 1, ans[i + n] = (i + 1) << 1;
		else
			ans[i] = (i + 1) << 1, ans[i + n] = i << 1 | 1;
	}
	FOR(i, 0, n << 1) printf("%d%c", ans[i], (i == (n << 1) - 1 ? '\n' : ' '));
	return 0;
}