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
const int max_n=100+5;
int a[max_n],b[max_n],c[max_n],ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=n;++i)
			scanf("%d",b+i);
		for(int i=1;i<=n;++i)
			scanf("%d",c+i);
		ans[1]=a[1];
		for(int i=2;i<n;++i)
		{
			if(ans[i-1]!=a[i]) ans[i]=a[i];
			else ans[i]=b[i];
		}
		if(a[n]!=ans[1]&&a[n]!=ans[n-1]) ans[n]=a[n];
		else if(b[n]!=ans[1]&&b[n]!=ans[n-1]) ans[n]=b[n];
		else ans[n]=c[n];
		for(int i=1;i<=n;++i)
			printf("%d%c",ans[i],i<n?' ':'\n');
	}
	return 0;
}