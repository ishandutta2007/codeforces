#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=1000050;
const int inf=1e9+7;
int a[N],b[N],par[N],sol;
vector<int> E[N];
int main()
{
    int n,i;
    scanf("%i",&n);
    vector<int> ans;
    for(i=2;i<=n+1;i++)
	{
		scanf("%i",&par[i]);
		E[par[i]].push_back(i);
		int add=1;
		int u=par[i],v=i;
		if(u==1) sol=max(sol,1);
		while(u)
		{
			if(u==1)
			{
				sol=max(sol,add);
			}
			else
			{
				int mx=0;
				int p=max(a[u],b[u]+1);
				if(add>a[u]) b[u]=a[u],a[u]=add;
				else b[u]=max(b[u],add);
				if(p==max(a[u],b[u]+1)) break;
			}
			add=max(a[u],b[u]+1);
			v=u;
			u=par[u];
		}
		printf("%i ",sol);
	}
	return 0;
}