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
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		if(k==1)
		{
			bool flag=true;
			for(int i=1;i<n;++i)
				if(a[i]!=a[i+1])
				{
					flag=false;
					break;
				}
			printf("%d\n",flag?1:-1);
			continue;
		}
		for(int i=1;i<=n;++i)
			++a[i];
		int cnt=0;
		for(int i=1;i<=n;++i)
			cnt+=a[i]!=a[i-1];
		if(cnt<=k)
			printf("%d\n",1);
		else
		{
			cnt-=k;
			printf("%d\n",1+(cnt+k-2)/(k-1));
		}
	}
	return 0;
}