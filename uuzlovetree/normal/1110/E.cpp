#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n;
ll c[maxn],t[maxn],x[maxn],y[maxn]; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%I64d",&t[i]);
	if(c[1]!=t[1]||c[n]!=t[n])
	{
		puts("No");
		return 0;
	}
	else
	{
		for(int i=2;i<=n;++i)x[i]=c[i]-c[i-1];
		for(int i=2;i<=n;++i)y[i]=t[i]-t[i-1];
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		bool yes=1;
		for(int i=1;i<=n;++i)if(x[i]!=y[i])yes=0;
		if(yes)puts("Yes");
		else puts("No");
	}
	return 0; 
}