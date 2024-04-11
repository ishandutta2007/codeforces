#include<stdio.h>
#include<vector>
int ufp[100001];
int c;
int getR(int x){return ufp[x]==x?x:(ufp[x]=getR(ufp[x]));}
void uni(int a, int b){a = getR(a); b = getR(b); if(a!=b){c++; ufp[a] = b;}}

std::vector<int> map[100001];
int v[100001];
bool hC[100001];
int dfs(int x)
{
	v[x] = 1;
	for(auto t: map[x])
	{
		if(v[t] == 0) dfs(t);
		else if(v[t] == 1)
		{
			hC[getR(t)] = true;
		}
	}
	v[x] = 2;
	return 0;
}


int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	c = 0;
	for(i=1; i<=n; i++) ufp[i] = i;
	for(i=1; i<=m; i++)
	{
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		uni(a, b);
	}
	for(i=1; i<=n; i++)
	{
		if(v[i] == 0) dfs(i);
	}
	for(i=1; i<=n; i++)
	{
		if(hC[getR(i)] == true)
		{
			c++;
			hC[getR(i)] = false;
		}
	}
	printf("%d", c);
	return 0;
}