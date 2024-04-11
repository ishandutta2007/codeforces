#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, w;

int ask(int x)
{
	printf("1 %d %d ", n - 1, x);
	rep1(i, n) if(i != x) printf("%d ", i);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;	
}

int ask(int l, int r)
{
	printf("1 %d 1 ", r - l + 1);
	for(int i = l; i <= r; i ++) printf("%d ", i);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

int solve(int l, int r)
{
	if(l == r) return l;
	int mid = l + r >> 1;
	if(ask(l, mid) == w) return solve(l, mid);
	else return solve(mid + 1, r);
}

void solve()
{
	scanf("%d", &n);
	w = ask(1);
	printf("-1 %d\n", ask(solve(2, n)));
	fflush(stdout);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}