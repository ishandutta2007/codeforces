#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n];
long long pref[max_n],suff[max_n];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=2;i<=n;++i)
		pref[i]=pref[i-1]+max(a[i-1]-a[i],0);
	for(int i=n-1;i>=1;--i)
		suff[i]=suff[i+1]+max(a[i+1]-a[i],0);
	while(m--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		if(s<t)
			printf("%lld\n",pref[t]-pref[s]);
		else
			printf("%lld\n",suff[t]-suff[s]);
	}
	return 0;
}