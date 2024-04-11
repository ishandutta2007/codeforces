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
        x=x*10+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
bool check(int x)
{
	if(x<2)
		return false;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
			return false;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int x=0;
		while(1)
		{
			if(!check(x)&&check(x+n-1))
				break;
			++x;
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				printf("%d%c",i==j?x:1,j<n?' ':'\n'); 
	}
	return 0;
}