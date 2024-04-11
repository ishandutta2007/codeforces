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
int work(int x)
{
	return x>=0?x:0;
}
int main()
{
	int n,a1,a2,a3,b1,b2,b3;
	scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&a3,&b1,&b2,&b3);
	printf("%d %d\n",work(a1+b2-n)+work(a2+b3-n)+work(a3+b1-n),min(a1,b2)+min(a2,b3)+min(a3,b1));
	return 0;
}