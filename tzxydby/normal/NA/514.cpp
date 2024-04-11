#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,m,a,b,c,s[N],t[N],v,p,q,mod,ans=LLONG_MAX;
struct mat{int a[2][2];}y;
mat operator*(mat x,mat y)
{
	mat z;
	z.a[0][0]=z.a[0][1]=z.a[1][0]=z.a[1][1]=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				z.a[i][j]=(z.a[i][j]+(__int128)x.a[i][k]*y.a[k][j]%mod)%mod;
	return z;
}
mat qp(mat a,int b){mat ans=a;b--;while(b){if(b&1)ans=ans*a;a=a*a;b>>=1;}return ans;}
long long cal(long long x){return qp(y,x).a[0][0];}
signed main()
{
	ios::sync_with_stdio(0);
	y.a[0][1]=y.a[1][0]=y.a[1][1]=1;
	cin>>n;
	mod=100000,v=n%mod,b=1;
	for(int i=1;;i++)
	{
		if(a==v)
			s[++p]=i;
		c=(a+b)%mod;
		a=b,b=c;
		if(a==0&&b==1)
			break;
	}
	for(mod=1000000,m=150000;mod<=10000000000000;mod*=10,m*=10)
	{
		v=n%mod,q=0;
		for(int i=1;i<=p;i++)
			for(int j=0;j<=9;j++)
				if(cal(s[i]+m*j)%mod==v)
					t[++q]=s[i]+m*j;
		for(int i=1;i<=q;i++)
			s[i]=t[i];
		p=q;
	}
	for(int i=1;i<=p;i++)
		ans=min(ans,s[i]);
	if(!p)
		ans=0;
	cout<<ans-1<<endl;
	return 0;
}