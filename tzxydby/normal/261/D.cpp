#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int q,n,b,t,a[N],f[N];
int main()
{
	scanf("%d%d%d%d",&q,&n,&b,&t);
	t=min(b,t);
	while(q--)
	{
		for(int i=1;i<=n;i++) 
			scanf("%d",&a[i]);
		for(int i=1;i<=b;i++)
			f[i]=0;
		for(int i=1;i<=t;i++)
			for(int j=1,k;j<=n;j++)
				for(f[a[j]]=f[a[j]-1]+1,k=a[j]+1;k<=b&&f[a[j]]>f[k];k++)
					f[k]=f[a[j]];
		printf("%d\n",f[b]);
	}
	return 0;
}