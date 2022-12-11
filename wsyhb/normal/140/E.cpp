#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buf_size=1<<20;
    char buf[buf_size],*S,*T;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buf_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        char c;
        do
            c=read_char();
        while(c<'0'||c>'9');
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^'0');
            c=read_char();
        }
        return x;
    }
}
const int max_n=1e6+5;
const int max_l=5e3+5;
int l[max_n],g[max_l][max_l],fac[max_l],A[max_l];
vector<int> f[max_n];
int main()
{
	int n=IO::read_int(),m=IO::read_int(),mod=IO::read_int(),L=0;
	for(int i=1;i<=n;++i)
	{
		l[i]=IO::read_int();
		L=max(L,l[i]);
	}
	g[1][1]=1;
	for(int i=2;i<=L;++i)
		for(int j=1;j<=min(i,m);++j)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j-1ll))%mod;
	L=min(L,m);
	fac[0]=A[0]=1;
	for(int i=1;i<=L;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		A[i]=A[i-1]*(m-i+1ll)%mod;
	}
	f[1].resize(min(l[1],m)+1);
	int sum=0;
	for(int j=1;j<=min(l[1],m);++j)
	{
		f[1][j]=1ll*g[l[1]][j]*A[j]%mod;
		sum+=f[1][j],sum-=sum>=mod?mod:0;
	}
	for(int i=2;i<=n;++i)
	{
		int R=min(l[i],m);
		f[i].resize(R+1);
		for(int j=1;j<=R;++j)
			f[i][j]=(1ll*g[l[i]][j]*A[j]%mod*sum+(j<=min(l[i-1],m)?1ll*(mod-f[i-1][j])*g[l[i]][j]%mod*fac[j]:0))%mod;
		sum=0;
		for(int j=1;j<=R;++j)
			sum+=f[i][j],sum-=sum>=mod?mod:0;
	}
	printf("%d\n",sum);
	return 0;
}