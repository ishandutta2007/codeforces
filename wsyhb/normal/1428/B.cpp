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
const int max_n=3e5+5;
char s[max_n];
bool mark[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s);
		bool flag1=true,flag2=true;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='<')
				flag1=false;
			if(s[i]=='>')
				flag2=false;
		}
		if(flag1||flag2)
		{
			printf("%d\n",n);
			continue;
		}
		for(int i=0;i<n;++i)
			mark[i]=false;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='-')
				mark[i]=mark[(i+1)%n]=true;
		}
		int cnt=0;
		for(int i=0;i<n;++i)
			 cnt+=mark[i];
			printf("%d\n",cnt);
	}
	return 0;
}