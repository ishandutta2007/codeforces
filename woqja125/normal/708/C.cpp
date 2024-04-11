#include<stdio.h>
#include<vector>
#include<algorithm>
std::vector<int> map[400001];
int N[400001];
int max[400001];
int ans[400001];
int n;
void dfs1(int x, int p)
{
	N[x]++;
	map[x].erase(std::remove(map[x].begin(), map[x].end(), p), map[x].end());
	for(auto xx: map[x])
	{
		dfs1(xx, x);
		N[x]+=N[xx];
		if(max[x] < max[xx]) max[x] = max[xx];
	}
	if(N[x] <= n/2) max[x] = N[x];
}
void dfs2(int x, int p, int pMax)
{
//	printf("$$%d %d\n", x, pMax);
	int M = -1;
	for(auto xx: map[x])
	{
		if(M==-1) M=xx;
		if(N[xx] > N[M]) M = xx;
	}
	if(M==-1 || N[M] < n-N[x])
	{
		if(n-N[x]-pMax <= n/2) ans[x] = 1;
	}
	else
	{
		if(N[M] - max[M] <= n/2) ans[x] = 1;
	}
	int len = map[x].size();
	if(len == 0) return;
	int *mlisti = new int[len];
	int *mlistd = new int[len];
	mlisti[0] = max[map[x][0]];
	for(int i=1; i<len; i++)
	{
		if(mlisti[i-1] > max[map[x][i]]) mlisti[i] = mlisti[i-1];
		else mlisti[i] = max[map[x][i]];
	}
	mlistd[len-1] = max[map[x][len-1]];
	for(int i=len-2; i>=0; i--)
	{
		if(mlistd[i+1] > max[map[x][i]]) mlistd[i] = mlistd[i+1];
		else mlistd[i] = max[map[x][i]];
	}
	for(int i=0; i<len; i++)
	{
		int cMax = pMax, xx=map[x][i];
//		printf("&&%d\n", cMax);
		if(n-N[xx] <= n/2 && cMax < n-N[xx]) cMax = n-N[xx];
//		printf("&&%d\n", cMax);
		if(i!=0)
		{
			if(cMax < mlisti[i-1]) cMax = mlisti[i-1];
		}
//		printf("&&%d\n", cMax);
		if(i!=len-1)
		{
			if(cMax < mlistd[i+1]) cMax = mlistd[i+1];
		}
	//	printf("&&%d\n", cMax);
		dfs2(xx, x, cMax);
	}
	delete[] mlisti;
	delete[] mlistd;
}
int main()
{
	int i;
	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	dfs1(1, -1);
//	for(int i=1; i<=n; i++) printf("##%d : %d %d\n", i, N[i], max[i]);
	dfs2(1, -1, 0);
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	return 0;
}