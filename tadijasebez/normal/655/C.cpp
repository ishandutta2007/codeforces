#include <stdio.h>
const int N=100050;
char s[N];
int a[N];
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int n;
int Get(int l, int r){ l=max(l,1);r=min(r,n);return a[r]-a[l-1];}
int main()
{
	int k,i;
	scanf("%i %i",&n,&k);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='0');
	int top=n,bot=0,mid,ans;
	while(top>=bot)
	{
		mid=top+bot>>1;
		bool ok=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1') continue;
			if(Get(i-mid,i+mid)>=k+1){ ok=1;break;}
		}
		if(ok) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",ans);
	return 0;
}