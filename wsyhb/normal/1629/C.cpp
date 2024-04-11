#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
vector<int> pos[max_n];
inline int find(int v,int p)
{
	int k=lower_bound(pos[v].begin(),pos[v].end(),p)-pos[v].begin();
	return k<int(pos[v].size())?pos[v][k]:-1;
}
int a[max_n];
bool vis[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n;++i)
			pos[i].clear();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			pos[a[i]].push_back(i);
		}
		vector<int> b;
		for(int i=1;i<=n;++i)
		{
			vis[a[i]]=true;
			int now=i;
			for(int k=0;;++k)
			{
				if(vis[k])
					continue;
				int p=find(k,now+1);
				if(p==-1)
				{
					b.push_back(k);
					break;
				}
				while(now<p)
					vis[a[++now]]=true;
			}
			for(int j=i;j<=now;++j)
				vis[a[j]]=false;
			i=now;
		}
		printf("%d\n",(int)b.size());
		for(int i=0;i<int(b.size());++i)
			printf("%d%c",b[i],i+1<int(b.size())?' ':'\n');
	}
	return 0;
}