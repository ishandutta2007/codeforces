#include<stdio.h>
#include<queue>
const int MAXN = 31*50000 + 10;
int a[50001];
int C[MAXN], c=-1, ch[MAXN][2], end[MAXN];
int ans[50001], ansc = 0;
int dfs(int x, int num, int M){
	if(num > M) return C[x];
	int remain = end[x];
	if(ch[x][0] != -1) remain += dfs(ch[x][0], num*2, M);
	if(ch[x][1] != -1) remain += dfs(ch[x][1], num*2+1, M);
	if(remain != 0)
	{
		remain--;
		ans[++ansc] = num;
	}
	return remain;
}
int main()
{
	int n, b;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	int now = ++c;
	ch[now][0] = ch[now][1] = -1;
	for(int i=1; i<=n; i++)
	{
		now = 0;
		C[now]++;
		for(b = 30; (a[i]&(1<<b)) == 0; b--);
		for(b--; b>=0; b--)
		{
			bool bit = (a[i]&(1<<b));
			if(ch[now][bit] == -1){
				ch[now][bit] = ++c; ch[c][0] = ch[c][1] = -1;
			}
			now = ch[now][bit];
			C[now] ++;
		}
		end[now] ++;
	}
	int f = n, r = 2147483647;
	while(f<r)
	{
		int m = (0ll+f+r)/2;
		ansc=-1;
		if(dfs(0, 1, m)) f = m+1;
		else r = m;
	}
	ansc=0;dfs(0, 1, f);
	for(int i=1; i<=ansc; i++) printf("%d ", ans[i]);
	return 0;
}