#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, rt[150005];

int root(int x)
{
	return rt[x] == x ? x : rt[x] = root(rt[x]);
}

int main()
{
	scanf("%d", &n);
	rep1(i, n) rt[i] = i;
	rep1(i, n) {
		int p;
		scanf("%d", &p);
		rt[root(p)] = root(i);
	}
	int ans = 0;
	rep1(i, n) if(root(i) == i) ans ++;
	printf("%d", ans);
	return 0;
}