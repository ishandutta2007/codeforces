//test again
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
inline void Write(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	static char st[13];
	int head=0;
	while(x)
	{
		st[++head]=x%10+'0';
		x/=10;
	}
	while(head>0)
		putchar(st[head--]);
}
typedef pair<int,int> P;
vector<P> now;
const int max_n=1e3+5;
P st[max_n];
int _top;
vector<P> ans;
int main()
{
	int n=read_int();
	for(int i=1;i<=n;++i)
	{
		int x=read_int();
		if(x)
			now.push_back(P(x,i));
	}
	if(now.size()<=1)
	{
		puts("-1");
		return 0;
	}
	sort(now.begin(),now.end());
	srand(time(NULL));
	while(now.size()>2)
	{
		int x,y;
		do
		{
			x=rand()%now.size();
			y=rand()%now.size();
		}while(x==y);
		if(now[x].first>now[y].first)
			swap(x,y);
		int p=now[x].second,q=now[y].second;
		ans.push_back(P(p,q));
		now[y].first-=now[x].first;
		now[x].first<<=1;
		if(now[y].first==0)
		{
			while(now.back().first)
			{
				st[++_top]=now.back();
				now.pop_back();
			}
			now.pop_back();
			while(_top>0)
				now.push_back(st[_top--]);
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<int(ans.size());++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}