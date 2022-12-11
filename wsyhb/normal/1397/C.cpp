#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
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
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=read_char();
    }
    return flag?-x:x;
}
const int p=50021;
int power(int a,int n)
{
	int ans=1;
	a%=p;
	while(n)
	{
		if(n&1) ans=1ll*ans*a%p;
		a=1ll*a*a%p;
		n>>=1;
	}
	return ans;
}
const int max_n=1e5+5;
long long a[max_n],b[max_n];
int main()
{
	int n=read_int();
	for(int i=1;i<=n;++i) a[i]=read_int();
	if(n==1)
	{
		printf("1 1\n");
		printf("%d\n",-a[1]);
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("0\n");
		return 0;
	}
	printf("%d %d\n",1,n-1);
	for(int i=1;i<=n-1;i++)
	{
		b[i]=1ll*(a[i]%n)*(n-1);
		a[i]+=b[i];
		printf("%lld%c",b[i],i<n-1?' ':'\n');
	}
	printf("%d %d\n",n,n);
	printf("%lld\n",-a[n]);
	printf("%d %d\n",1,n);
	a[n]=0;
	for(int i=1;i<=n;i++) printf("%lld%c",-a[i],i<n?' ':'\n');
	return 0;
}