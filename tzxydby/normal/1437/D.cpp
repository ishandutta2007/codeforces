#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N],d[N],q[N],b,e,p,mx;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		b=0,e=1,q[0]=1,p=2,mx=0;
		while(p<=n)
		{
			int f=q[b++];
			while(1)
			{
				q[e++]=a[p];
				d[a[p]]=d[f]+1;
				mx=max(mx,d[a[p]]);
				p++;
				if(p>n||a[p]<a[p-1])
					break;
			}
		}
		printf("%d\n",mx);
	}
	return 0;
}