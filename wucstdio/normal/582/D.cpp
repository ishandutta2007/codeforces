#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
char s[1005];
ll p,alpha,f[2][3505][2][2];
int a[2][1005],digit[3505];
ll ask(ll l,ll r)
{
	if(l>r)return 0;
	if(r<p)return ((r+2)*(r+1)/2-l*(l+1)/2)%MOD;
	if(l>=p)return ((2*p-1)*(r-l+1)-r*(r+1)/2+l*(l-1)/2)%MOD;
	return ask(l,p-1)+ask(p,r);
}
int main()
{
	scanf("%lld%lld",&p,&alpha);
	scanf("%s",s+1);
	a[0][0]=(int)strlen(s+1);
	for(int i=1;i<=a[0][0];i++)
	  a[0][i]=s[a[0][0]-i+1]-'0';
	while(a[digit[0]&1][0])
	{
		digit[0]++;
		bool x=digit[0]&1;
		ll r=0;
		for(int i=a[!x][0];i>=1;i--)
		{
			r=r*10+a[!x][i];
			a[x][i]=(int)(r/p);
			r%=p;
		}
		digit[digit[0]]=(int)r;
		a[x][0]=a[!x][0];
		while(a[x][0]&&a[x][a[x][0]]==0)a[x][0]--;
	}
	for(int i=1;i*2<=digit[0];i++)swap(digit[i],digit[digit[0]-i+1]);
	f[0][0][0][1]=1;
	for(int i=1;i<=digit[0];i++)
	{
		for(int j=0;j<i;j++)
		{
			f[i&1][j][0][0]=(f[i&1][j][0][0]+f[(i-1)&1][j][0][0]*ask(0,p-1))%MOD;
			f[i&1][j+1][1][0]=(f[i&1][j+1][1][0]+f[(i-1)&1][j][0][0]*ask(0,p-2))%MOD;
			
			f[i&1][j][0][0]=(f[i&1][j][0][0]+f[(i-1)&1][j][1][0]*ask(p,2*p-1))%MOD;
			f[i&1][j+1][1][0]=(f[i&1][j+1][1][0]+f[(i-1)&1][j][1][0]*ask(p-1,2*p-2))%MOD;
			
			f[i&1][j][0][0]=(f[i&1][j][0][0]+f[(i-1)&1][j][0][1]*ask(0,digit[i]-1))%MOD;
			f[i&1][j+1][1][0]=(f[i&1][j+1][1][0]+f[(i-1)&1][j][0][1]*ask(0,digit[i]-2))%MOD;
			f[i&1][j][0][1]=(f[i&1][j][0][1]+f[(i-1)&1][j][0][1]*ask(digit[i],digit[i]))%MOD;
			if(digit[i])f[i&1][j+1][1][1]=(f[i&1][j+1][1][1]+f[(i-1)&1][j][0][1]*ask(digit[i]-1,digit[i]-1))%MOD;
			
			f[i&1][j][0][0]=(f[i&1][j][0][0]+f[(i-1)&1][j][1][1]*ask(p,p+digit[i]-1))%MOD;
			f[i&1][j+1][1][0]=(f[i&1][j+1][1][0]+f[(i-1)&1][j][1][1]*ask(p-1,p+digit[i]-2))%MOD;
			f[i&1][j][0][1]=(f[i&1][j][0][1]+f[(i-1)&1][j][1][1]*ask(p+digit[i],p+digit[i]))%MOD;
			f[i&1][j+1][1][1]=(f[i&1][j+1][1][1]+f[(i-1)&1][j][1][1]*ask(p+digit[i]-1,p+digit[i]-1))%MOD;
			
			f[(i-1)&1][j][0][0]=0;
			f[(i-1)&1][j][0][1]=0;
			f[(i-1)&1][j][1][0]=0;
			f[(i-1)&1][j][1][1]=0;
		}
//		printf("%d %d:",i,digit[i]);
//		for(int j=0;j<=i;j++)
//		  printf("(%lld,%lld) ",f[i][j][0][0]+f[i][j][0][1],f[i][j][1][0]+f[i][j][1][1]);
//		printf("\n");
	}
	ll ans=0;
	for(int i=(int)alpha;i<=digit[0];i++)
	  ans+=f[digit[0]&1][i][0][0]+f[digit[0]&1][i][0][1];
	printf("%lld\n",ans%MOD);
	return 0;
}