#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a[1005], b[1005];
int ask(int l, int r)
{
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int main()
{
	scanf("%d", &n);
	rep1(i, n - 1) b[i] = ask(i, i + 1);
	int x = ask(1, 3);
	a[3] = x - b[1];
	a[2] = b[2] - a[3];
	a[1] = b[1] - a[2];
	for(int i = 4; i <= n; i ++) a[i] = b[i - 1] - a[i - 1];
	printf("! "); rep1(i, n) printf("%d ", a[i]); fflush(stdout);
	return 0;
}