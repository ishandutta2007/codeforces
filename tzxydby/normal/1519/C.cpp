#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,u[N],v[N];
vector<int>a[N];
long long s[N],ps[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i].clear();
		s[i]=0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&u[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
		a[u[i]].push_back(v[i]);
	for(int i=1;i<=n;i++)
	{
		int m=a[i].size();
		if(!m)
			continue;
		sort(a[i].begin(),a[i].end());
		reverse(a[i].begin(),a[i].end());
		ps[0]=a[i][0];
		for(int j=1;j<m;j++)
			ps[j]=ps[j-1]+a[i][j];
		for(int j=1;j<=m;j++)
			s[j]+=(m%j?ps[m-m%j-1]:ps[m-1]);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",s[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}