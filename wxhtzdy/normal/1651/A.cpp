#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;

void solve()
{
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}