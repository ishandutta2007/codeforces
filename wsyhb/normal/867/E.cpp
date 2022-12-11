#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
bool flag_EOF;
inline char read_char()
{
    if(S==T)
		T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    int flag=1;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        if(c==EOF)
        {
            flag_EOF=true;
            return 0;
        }
        flag=(c=='-'?-1:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=x*10+(c^48);
        c=read_char();
    }
    return x*flag;
}
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	int n=read_int();
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int p=read_int();
		if(q.size())
		{
			int x=q.top();
			if(p>x)
			{
				ans+=p-x;
				q.pop();
				q.push(p);
			}
		}
		q.push(p);
	}
	printf("%lld",ans);
	return 0;
}