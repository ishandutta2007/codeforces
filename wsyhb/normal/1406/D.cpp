#include<bits/stdc++.h>
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
        x=(x<<3)+(x<<1)+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
const int max_n=1e5+5;
long long a[max_n],b[max_n];
int main()
{
	int n=read_int();
	for(int i=1;i<=n;++i) a[i]=read_int();
	long long x=0,y=0;
	for(int i=1;i<n;++i)
	{
		b[i]=a[i+1]-a[i];
		if(b[i]>0) x+=b[i];
		else y-=b[i];
	}
	long long res=a[1]+x;
	printf("%lld\n",res/2+(res%2==1));
	int q=read_int();
	for(int i=1;i<=q;++i)
	{
		int l=read_int(),r=read_int(),v=read_int();
		if(l>1)
		{
			if(b[l-1]>0) x-=b[l-1];
			b[l-1]+=v;
			if(b[l-1]>0) x+=b[l-1];
		}
		if(r<n)
		{
			if(b[r]>0) x-=b[r];
			b[r]-=v;
			if(b[r]>0) x+=b[r];
		}
		if(l==1) a[1]+=v;
		long long res=a[1]+x;
		printf("%lld\n",res/2+(res%2==1));
	}
	return 0;
}