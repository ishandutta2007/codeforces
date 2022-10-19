#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,ans[N],l,r,v;
char s[N];
struct ha
{
	int mod,p[N],a[N];
	void init(int v)
	{
		mod=v;
		p[0]=1;
		for(int i=1;i<=n;i++)
			p[i]=31ll*p[i-1]%mod;
		for(int i=1;i<=n;i++)
			a[i]=(31ll*a[i-1]+s[i]-'a')%mod;
	}
	int cal(int l,int r){return (a[r]+mod-1ll*a[l-1]*p[r-l+1]%mod)%mod;}
}h1,h2;
int ok(int l1,int r1,int l2,int r2){return h1.cal(l1,r1)==h1.cal(l2,r2)&&h2.cal(l1,r1)==h2.cal(l2,r2);}
int main()
{
	scanf("%d%s",&n,s+1);
	h1.init(1000000007);
	h2.init(1000000009);
	if(n&1)
		l=r=(n+1)/2;
	else
		l=n/2,r=l+1;
	v=1;
	for(int i=(n+1)/2;i>=1;i--)
	{
		v+=2;
		while(v>=r-l+1)
			v-=2;
		while(v>0)
		{
			if(!ok(l,l+v-1,r-v+1,r))
				v-=2;
			else
				break;
		}
		ans[i]=v;
		l--,r++;
	}
	for(int i=1;i<=(n+1)/2;i++)
		printf("%d ",ans[i]);
	return 0;
}