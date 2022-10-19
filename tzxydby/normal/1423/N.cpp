#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,x[N],y[N],w[N],s[N],v[N],a[N];
vector<pair<int,int>>e[N];
vector<int>r;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		w[i]=1,s[x[i]]++,s[y[i]]++;
		if(x[i]>y[i])
			swap(x[i],y[i]);
		e[y[i]].emplace_back(x[i],i);
	}
	for(int i=1;i<=n;i++)
	{
		for(auto j:e[i])
		{
			int p=j.first,q=j.second;
			if(!v[p])
			{
				v[p]=1;
				w[q]=0;
				s[i]--;
			}
			a[s[p]]=1;
		}
		for(auto j:e[i])
		{
			int p=j.first,q=j.second;
			if(!a[s[i]])
				break;
			s[i]++;
			v[p]=0;
			w[q]++;
		}
		for(auto j:e[i])
			a[s[j.first]]=0;
	}
	for(int i=1;i<=n;i++)
		if(v[i])
			r.push_back(i);
	printf("%d\n",r.size());
	for(auto i:r)
		printf("%d ",i);
	if(r.size())
		puts("");
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",x[i],y[i],w[i]);
	return 0;
}