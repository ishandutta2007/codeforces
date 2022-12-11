#include<bits/stdc++.h>
using namespace std;
namespace IO
{
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
	        flag=(c=='-'?-1:1);
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
	char st[13];
	int _top;
	void Write(int x)
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
		while(x)
		{
			st[++_top]=x%10+'0';
			x/=10;
		}
		while(_top>0)
			putchar(st[_top--]);
	}
}
const int max_n=1e5+5;
int cnt[max_n],b[max_n];
struct cmp
{
	inline bool operator () (int x,int y)
	{
		return cnt[x]!=cnt[y]?cnt[x]<cnt[y]:x<y;
	}
};
priority_queue<int,vector<int>,cmp> q;
set<int,cmp> s;
typedef pair<int,int> P;
vector<P> inter;
vector<int> ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n+1;++i)
			cnt[i]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",b+i);
			++cnt[b[i]];
		}
		while(q.size())
			q.pop();
		s.clear();
		inter.clear();
		for(int i=1;i<=n+1;++i)
			ans[i].clear();
		int col=0;
		for(int i=1;i<=n+1;++i)
		{
			if(cnt[i]>0)
				q.push(i);
			else
				col=i;
		}
		for(int k=1;k<=x;++k)
		{
			int now=q.top();
//			fprintf(stderr,"now=%d\n",now);
			q.pop();
			--cnt[now];
			if(cnt[now]>0)
				q.push(now);
//			fprintf(stderr,"cnt[now]=%d %d\n",cnt[now],q.top());
			ans[now].push_back(now);
		}
		if(y==n&&((y-x)&1))
		{
			if(q.size()<3)
			{
				puts("NO");
				continue;
			}
			int a,b,c;
			a=q.top();
			q.pop();
			b=q.top();
			q.pop();
			c=q.top();
			q.pop();
			ans[a].push_back(b);
			ans[b].push_back(c);
			ans[c].push_back(a);
			--cnt[a];
			if(cnt[a]>0)
				q.push(a);
			--cnt[b];
			if(cnt[b]>0)
				q.push(b);
			--cnt[c];
			if(cnt[c]>0)
				q.push(c);
			y-=3;
		}
//		fprintf(stderr,"cnt:");
//		for(int i=1;i<=n;++i)
//			fprintf(stderr,"%d%c",cnt[i],i<n?' ':'\n');
		for(int i=1;i<=n+1;++i)
		{
			if(cnt[i]>0)
			{
				s.insert(i);
//				fprintf(stderr,"i=%d\n",i);
			}
		}
		while(1)
		{
			while(s.size()&&cnt[*s.begin()]==0)
				s.erase(*s.begin());
			if(s.size()<2)
				break;
			int x=*(--s.end());
			s.erase(x);
			int y=*s.begin();
			s.erase(y);
			inter.push_back(P(x,y));
//			fprintf(stderr,"x=%d y=%d\n",x,y);
			--cnt[x],--cnt[y];
			if(cnt[x]>0)
				s.insert(x);
			if(cnt[y]>0)
				s.insert(y);
		}
		if(int(inter.size())*2<y-x)
		{
			puts("NO");
			continue;
		}
		for(int i=0;i<int(inter.size())&&y>x;++i)
		{
			int a=inter[i].first,b=inter[i].second;
			ans[a].push_back(b);
			--y;
			if(y>x)
			{
				ans[b].push_back(a);
				--y;
			}
		}
		puts("YES");
		for(int i=1;i<=n;++i)
		{
			int ans_now;
			if(ans[b[i]].empty())
				ans_now=col;
			else
			{
				ans_now=ans[b[i]].back();
				ans[b[i]].pop_back();
			}
			printf("%d%c",ans_now,i<n?' ':'\n');
		}
	}
	return 0;
}