#include<bits/stdc++.h>
using namespace std;
const int max_k=12+5;
const int max_n=1e5+5;
int a[max_k][max_n],id[max_k],key;
inline bool cmp(int x,int y)
{
	return a[x][key]>a[y][key];
}
const int max_cnt=12+1e5+5;
const int max_S=1<<12;
bitset<max_S> f[max_cnt];
int main()
{
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=k;++i)
	{
		for(int S=0;S<(1<<k);++S)
			f[i][S]=S>>(i-1)&1;
		id[i]=i;
	}
	int cnt=k;
	while(q--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			f[++cnt]=f[x]|f[y];
		else if(t==2)
			f[++cnt]=f[x]&f[y];
		else
		{
			key=y;
			sort(id+1,id+k+1,cmp);
			int S_now=0;
			for(int i=1;i<=k;++i)
			{
				S_now|=1<<(id[i]-1);
				if(f[x][S_now])
				{
					printf("%d\n",a[id[i]][y]);
					break;
				}
			}
		}
	}
	return 0;
}