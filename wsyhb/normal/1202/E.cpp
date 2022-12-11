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
	inline void read_string(char *s)
	{
		char x;
		do
		{
			x=read_char();
		}while(x<'a'||x>'z');
		int len=0;
		while(x>='a'&&x<='z')
		{
			s[len++]=x;
			x=read_char();
		}
		s[len]='\0';
	}
	char fw[buffer_size];
	int pw;
	inline void flush()
	{
		fwrite(fw,1,pw,stdout);
	}
	inline void write_char(char x)
	{
		if(pw==buffer_size)
		{
			flush();
			pw=0;
		}
		fw[pw++]=x;
	}
	char st[13];
	int top;
	inline void write_int(int x)
	{
		if(!x)
		{
			write_char('0');
			return;
		}
		if(x<0)
		{
			write_char('-');
			x=-x;
		}
		while(x)
		{
			st[++top]=x%10+'0';
			x/=10;
		}
		while(top>0)
			write_char(st[top--]);
	}
	inline void write_string(const char *s)
	{
		for(int i=0;s[i];++i)
			write_char(s[i]);
	}
}
const int max_tot=2e5+5;
struct AC
{
	int tr[max_tot][26],cnt[max_tot],sum[max_tot],fail[max_tot],tot;
	inline void insert(const char *s)
	{
		int cur=0;
		for(int i=0;s[i];++i)
		{
			int v=s[i]-'a';
			if(!tr[cur][v])
				tr[cur][v]=++tot;
			cur=tr[cur][v];
		}
		++cnt[cur];
	}
	int que[max_tot],head,tail;
	inline void build()
	{
		head=1,tail=0;
		for(int i=0;i<26;++i)
		{
			int u=tr[0][i];
			if(u)
			{
				sum[u]=cnt[u];
				que[++tail]=u;
			}
		}
		while(head<=tail)
		{
			int u=que[head++];
			for(int i=0;i<26;++i)
			{
				int v=tr[u][i];
				if(v)
				{
					fail[v]=tr[fail[u]][i];
					sum[v]=sum[fail[v]]+cnt[v];
					que[++tail]=v;
				}
				else
					tr[u][i]=tr[fail[u]][i];
			}
		}
	}
	inline vector<int> query(const char *s)
	{
		int len=strlen(s);
		vector<int> res(len);
		int cur=0;
		for(int i=0;i<len;++i)
		{
			cur=tr[cur][s[i]-'a'];
			res[i]=sum[cur];
		}
		return res;
	}
}pre,suf;
const int max_len=2e5+5;
char t[max_len],s[max_len];
int main()
{
	IO::read_string(t);
	int len=strlen(t);
	int n=IO::read_int();
	for(int i=1;i<=n;++i)
	{
		IO::read_string(s);
		pre.insert(s);
		reverse(s,s+strlen(s));
		suf.insert(s);
	}
	pre.build(),suf.build();
	vector<int> cnt_pre=pre.query(t);
	reverse(t,t+len);
	vector<int> cnt_suf=suf.query(t);
	reverse(cnt_suf.begin(),cnt_suf.end());
	long long ans=0;
	for(int i=0;i+1<len;++i)
		ans+=1ll*cnt_pre[i]*cnt_suf[i+1];
	printf("%lld\n",ans);
	return 0;
}