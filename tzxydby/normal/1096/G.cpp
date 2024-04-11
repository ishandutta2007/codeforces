#include<bits/stdc++.h>
using namespace std;
const int N=4000005,mod=998244353;
int n,k,rev[N],ans;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void ntt(vector<int>&a,int f)
{
	int n=a.size();
	for(int i=0;i<n;i++)
		if(i<rev[i])
			swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1)
	{
		int wn=qp(f?(mod+1)/3:3,(mod-1)/(i<<1));
		for(int j=0;j<n;j+=(i<<1))
		{
			int w=1;
			for(int k=0;k<i;k++,w=1ll*w*wn%mod)
			{
				int x=a[j+k],y=1ll*w*a[j+k+i]%mod;
				a[j+k]=(x+y>=mod?x+y-mod:x+y);
				a[j+k+i]=(x-y<0?x-y+mod:x-y);
			}
		}
	}
	if(f)
	{
		int iv=qp(n,mod-2);
		for(int i=0;i<n;i++)
			a[i]=1ll*a[i]*iv%mod;
	}
}
vector<int>mul(vector<int>x,vector<int>y)
{
	int n=1,l=0,m=x.size()+y.size()-1;
	while(n<m)
		n<<=1,l++;
	for(int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	x.resize(n),y.resize(n);
	ntt(x,0),ntt(y,0);
	for(int i=0;i<n;i++)
		x[i]=1ll*x[i]*y[i]%mod;
	ntt(x,1);
	x.resize(m);
	return x;
}
vector<int>qp(vector<int>a,int b)
{
	vector<int>ans={1};
	while(b)
	{
		if(b&1)
			ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	n/=2;
	vector<int>a(10,0);
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]=1;
	}
	a=qp(a,n);
	for(int i=0;i<a.size();i++)
		ans=(ans+1ll*a[i]*a[i]%mod)%mod;
	printf("%d\n",ans);
	return 0;
}