#include<stdio.h>
typedef long long ll;
int n,x,y,a[20],t[10],p=1000000007;
ll pw(ll x,ll y)
{
	ll _=1;
	for(;y;y>>=1)
	{
		if(y&1)
			_=_*x%p;
		x=x*x%p;
	}
	return _;
}
ll C(ll x,ll y)
{
	ll _=1;
	for(int i=0;i<y;i++)
		_=_*(x-i)%p*pw(i+1,p-2)%p;
	return _;
}
ll f[200][7],z,s;
int main()
{
	scanf("%d",&n),n++;
	for(int i=t[0]=1;i<10;i++)
		t[i]=t[i-1]*10;
	for(int i=10;i--;)
	{
		int u=n/t[i]%10;
		for(int j=0;j<u;j++)
		{
			y=x+(j==4||j==7);
			for(int k=0;k<=i;k++)
				a[k+y]+=pw(8,i-k)*pw(2,k)*C(i,k);
		}
		x+=u==4||u==7;
	}
	a[0]--;
	f[0][0]=1;
	for(int i=0;i<10;i++)
		for(int j=80;j>=0;j--)
			for(int k=6;k--;)
				for(int l=1;l+k<7;l++)
					f[j+i*l][k+l]=(f[j+i*l][k+l]+f[j][k]*C(a[i],l))%p;
	for(int i=10;i--;)
		z=(z+f[i][6]*s)%p,s+=a[i];
	for(int i=1;i<7;i++)
		z=z*i%p;
	printf("%I64d",z);
	return 0;
}