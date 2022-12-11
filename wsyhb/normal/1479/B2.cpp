#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],id[max_n],f[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i]==a[i-1])
			--i,--n;
	}
	for(int i=1;i<=n;++i)
	{
		id[a[i-1]]=i;
		f[i]=f[i-1]-(i-1)+1;
		int j=id[a[i]];
		if(j)
			f[i]=min(f[i],f[j]-j);
		f[i]+=i-1;
	}
	int ans=n;
	for(int i=1;i<=n;++i)
		ans=min(ans,f[i]+(n-i));
	printf("%d\n",ans);
	return 0;
}