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
const int max_n=2e5+5;
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int cnt_a=0,cnt_b=0;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='A')
				++cnt_a;
			else
			{
				if(cnt_a>0)
				{
					--cnt_a;
					ans+=2;
				}
				else if(cnt_b>0)
				{
					--cnt_b;
					ans+=2;
				}
				else
					++cnt_b;
			}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}