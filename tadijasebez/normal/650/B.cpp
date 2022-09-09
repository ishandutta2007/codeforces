#include <stdio.h>
const int N=500050;
int c[N],dl[N],dr[N];
char s[N];
int min(int a, int b){ return a>b?b:a;}
bool Check(int mid, int n, int t, int a)
{
	int i,j;
	for(i=1;i<=mid;i++)
	{
		j=mid-i;
		int tmp=a*min(i-1,j);
		tmp+=dl[i];
		tmp+=dr[n-j+1];
		if(tmp<=t) return 1;
	}
	return 0;
}
int main()
{
	int n,a,b,t,i;
	scanf("%i %i %i %i",&n,&a,&b,&t);
	scanf("%s",s+1);
	c[1]=(s[1]=='w'?b+1:1);
	for(i=2;i<=n;i++) c[i]=(s[i]=='w'?b+1:1)+a;
	for(i=1;i<=n;i++) dl[i]=dl[i-1]+c[i];
	for(i=n;i>=1;i--) dr[i]=dr[i+1]+c[i];
	if(dl[n]<=t) return printf("%i\n",n),0;
	int top=n-1,bot=1,mid,ans=0;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid,n,t,a)) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	printf("%i\n",ans);
	return 0;
}