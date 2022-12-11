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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		int ans=63244;
		for(int i=0;i<=63244;++i)
		{
			int delta=n-(i+1);
			if(delta<0) break;
			ans=min(ans,i+(delta+i)/(i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}