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
const int max_n=1e5+5;
int a[max_n];
long long b[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	sort(a,a+n);
	long long ans=1e18;
	for(int c=1;;++c)
	{
		b[0]=1;
		bool flag=true;
		for(int i=1;i<n;++i)
		{
			b[i]=b[i-1]*c;
			if(b[i]<0||b[i]>1e14)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			long long now=0;
			for(int i=0;i<n;++i) now+=abs(a[i]-b[i]);
			ans=min(ans,now);
		}
		else break;
	}
	printf("%lld",ans);
	return 0;
}