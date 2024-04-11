#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
bool flag_EOF;
inline char read_char()
{
    if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    bool flag=false;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        if(c==EOF)
        {
            flag_EOF=true;
            return 0;
        }
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=x*10+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
const int max_n=3e5+5;
int a[max_n];
const int P=998244353;
int fac[max_n],inv[max_n],inv_fac[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n*2;++i)
		scanf("%d",a+i);
	sort(a+1,a+n*2+1);
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans-=a[i];
	for(int i=n+1;i<=n*2;++i)
		ans+=a[i];
	ans%=P;
	fac[0]=inv_fac[0]=1;
	fac[1]=inv[1]=inv_fac[1]=1;
	for(int i=2;i<=n*2;++i)
	{
		fac[i]=1ll*fac[i-1]*i%P;
		inv[i]=1ll*(P-P/i)*inv[P%i]%P;
		inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%P;
	}
	printf("%lld",ans*fac[n*2]%P*inv_fac[n]%P*inv_fac[n]%P);
	return 0;
}