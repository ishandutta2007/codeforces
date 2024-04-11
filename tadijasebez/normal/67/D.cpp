#include <stdio.h>
const int N=1000050;
int a[N],b[N],id[N],m,sol[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]),id[b[i]]=i;
	for(i=1;i<=n;i++)
	{
		int top=m,bot=1,mid,ans=m+1;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(id[a[sol[mid]]]<id[a[i]]) ans=mid,top=mid-1;
			else bot=mid+1;
		}
		if(ans==m+1) m++;
		sol[ans]=i;
	}
	printf("%i\n",m);
	return 0;
}