#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, p[100005];

void solve() 
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &p[i]);
	int mx = 0, ans = 0;
	rep1(i, n) {
		mx = max(mx, p[i]);
		ans += mx == i;
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();	
	return 0;
}