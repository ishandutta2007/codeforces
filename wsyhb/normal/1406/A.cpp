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
const int max_a=100+5;
int cnt[max_a];
int main()
{
	int t=read_int();
	while(t--)
	{
		int n=read_int();
		for(int i=0;i<=100;++i) cnt[i]=0;
		for(int i=1;i<=n;++i)
		{
			int x=read_int();
			cnt[x]++;
		}
		int ans=0;
		for(int i=0;i<=100;++i)
			if(!cnt[i])
			{
				ans+=i;
				for(int j=0;j<i;++j)
					cnt[j]--;
				break;
			}
		for(int i=0;i<=100;++i)
			if(!cnt[i])
			{
				ans+=i;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}