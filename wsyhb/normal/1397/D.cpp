#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
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
        x=(x<<3)+(x<<1)+(c-'0');
        c=read_char();
    }
    return flag?-x:x;
}
priority_queue<int> q;
int Last[2];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		while(q.size()) q.pop();
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int x;
			scanf("%d",&x);
			q.push(x);
		}
		Last[0]=Last[1]=0;
		int id=1;
		while(1)
		{
			if(Last[id]) q.push(Last[id]);
			if(q.empty()) break;
			Last[id]=q.top()-1;
			q.pop();
			id^=1;
		}
		printf(id?"HL\n":"T\n");
	}
	return 0;
}