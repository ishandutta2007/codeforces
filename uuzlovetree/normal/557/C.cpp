#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
struct data
{
	int len,d;
}a[maxn];
int has[205][maxn];
vector<int> v[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].len);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].d);
	for(int i=1;i<=n;++i)v[a[i].len].push_back(a[i].d);
	for(int L=1;L<=maxn-5;++L)
	{
		for(int j=1;j<=200;++j)has[j][L]=has[j][L-1];
		for(int i=0;i<v[L].size();++i)has[v[L][i]][L]++;
	}
	int t=0,left=n;
	int ans=(int)1e9;
	for(int L=maxn-5;L;--L)if(v[L].size())
	{
		int sz=v[L].size();
		left-=sz;
		int k=sz-1;
		int x=left-k;
		if(x<=0)ans=min(ans,t);
		else
		{
			int p=0;
			for(int j=1;j<=200;++j)
			{
				int y=has[j][L-1];
				if(x>=y)x-=y,p+=y*j;
				else p+=x*j,x=0;
				if(!x)break;
			}
			ans=min(ans,t+p);
		}
		for(int i=0;i<v[L].size();++i)t+=v[L][i];
	}
	printf("%d\n",ans);
	return 0;
}