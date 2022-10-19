#include<bits/stdc++.h>
using namespace std;
const int N=2000005,mod=998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int n,m=(1<<20),ivm,k,l=20,r[N],w1[N],w2,a[N],ans[N],b[N];
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x;
}
void wt(int x)
{
	char b[10];int k=0;
	while(x)
		b[k++]=x%10,x/=10;
	for(int i=k-1;i>=0;i--)
		putchar(b[i]+'0');
	putchar(' ');
}
void ntt(int *a,int t)
{
	for(int i=0;i<m;i++)
		if(i<r[i])
			swap(a[i],a[r[i]]);
	for(int mid=1;mid<m;mid<<=1)
	{
		int wn=qp(t?3:332748118,(mod-1)/(mid<<1));
		for(int j=0;j<m;j+=(mid<<1))
		{
			int w=1;
			for(int k=0;k<mid;k++,w=1ll*w*wn%mod)
			{
				int x=a[j+k],y=1ll*w*a[j+k+mid]%mod;
				a[j+k]=(x+y)%mod;
				a[j+k+mid]=(x-y+mod)%mod;
			}
		}
	}
}
void mul(int *a,int *b)
{
	ntt(a,1);
	ntt(b,1);
	for(int i=0;i<m;i++)
		a[i]=1ll*a[i]*b[i]%mod;
	ntt(a,0);
	for(int i=0;i<m;i++)
		a[i]=1ll*a[i]*ivm%mod;
	for(int i=0;i<m;i++)
		if(a[i])
			a[i]=1;
}
int main()
{
	n=rd(),k=rd();
	for(int i=0;i<n;i++)
		a[rd()]=1;
	for(int i=0;i<m;i++)
		r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	ivm=qp(m,mod-2);
	ans[0]=1;
	while(k)
	{
		if(k&1)
		{
			for(int i=0;i<m;i++)
				b[i]=a[i];
			mul(ans,b);
		}
		for(int i=0;i<m;i++)
			b[i]=a[i];
		mul(a,b);
		k>>=1;
	}
	for(int i=0;i<m;i++)
		if(ans[i])
			wt(i);
	return 0;
}