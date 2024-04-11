#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m, u[150005], v[150005], rt[150005];
int a[150005], b[150005];

int root(int x)
{
	return rt[x] == x ? x : rt[x] = root(rt[x]);
}

int main()
{
	scanf("%d%d", &n, &m);
	rep1(i, n) rt[i] = i;
	rep(i, m) {
		scanf("%d%d", &v[i], &u[i]);
		rt[root(u[i])] = root(v[i]);
	}
	rep1(i, n) a[root(i)]++;
	rep(i, m) b[root(u[i])]++;
	bool ok = true;
	rep1(i, n) if(b[i] != a[i] * 1LL * (a[i] - 1) / 2) ok = false;
	puts(ok ? "YES" : "NO");
	return 0;
}