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
struct patter
{
	string s;
	int id;
}p[max_n],now;
inline bool cmp(const patter &a,const patter &b)
{
	return a.s<b.s;
}
const int max_e=16e5+5;
int End[max_e],Last[max_n],Next[max_e],d[max_n],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	++d[y];
//	fprintf(stderr,"add_edge(x=%d,y=%d)\n",x,y);
}
int q[max_n],_head,_tail;
vector<int> ord;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
//	fprintf(stderr,"n=%d m=%d k=%d\n",n,m,k);
	for(int i=1;i<=n;++i)
	{
		cin>>p[i].s;
		p[i].id=i;
//		cerr<<"i="<<i<<" p[i].s="<<p[i].s<<"\n";
	}
	sort(p+1,p+n+1,cmp);
//	for(int i=1;i<=n;++i)
//		cerr<<"i="<<i<<" p[i].s="<<p[i].s<<"\n";
	now.s.resize(k);
	for(int i=1;i<=m;++i)
	{
		string s;
		int mt;
		cin>>s>>mt;
//		cerr<<"i="<<i<<" s[i]="<<s<<"\n";
//		fprintf(stderr,"mt=%d\n",mt);
		bool ok=false;
		for(int t=0;t<(1<<k);++t)
		{
			for(int j=0;j<k;++j)
				now.s[j]=t&(1<<j)?'_':s[j];
//			cerr<<"now="<<now.s<<"\n";
			int x=lower_bound(p+1,p+n+1,now,cmp)-p;
			if(x<=n&&p[x].s==now.s)
			{
				if(p[x].id==mt)
					ok=true;
				else	
					add_edge(mt,p[x].id);
			}
		}
		if(!ok)
		{
			puts("NO");
			return 0;
		}
	}
	_head=1,_tail=0;
	for(int i=1;i<=n;++i)
	{
		if(!d[i])
		{
			q[++_tail]=i;
//			fprintf(stderr,"push i=%d\n",i);
		}
	}
	while(_head<=_tail)
	{
		int x=q[_head++];
		ord.push_back(x);
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			--d[y];
			if(!d[y])
				q[++_tail]=y;
		}
	}
	if(int(ord.size())==n)
	{
		puts("YES");
		for(int i=0;i<n;++i)
			printf("%d%c",ord[i],i+1<n?' ':'\n');
	}
	else
		puts("NO"); 
	return 0;
}