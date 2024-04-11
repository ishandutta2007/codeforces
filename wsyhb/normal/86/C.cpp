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
		}while(x<'A'||x>'Z');
		int len=0;
		while(x>='A'&&x<='Z')
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
const int P=1e9+9;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=P?P:0);
}
const int max_tot=100+5;
int tr[max_tot][4],Len[max_tot],fail[max_tot],f[max_tot],tot;
namespace AC
{
	inline int To_int(char x)
	{
		return x=='A'?0:(x=='C'?1:(x=='G'?2:3));
	}
	inline void insert(const char *s)
	{
		int cur=0,len=strlen(s);
		for(int i=0;i<len;++i)
		{
			int v=To_int(s[i]);
			if(!tr[cur][v])
				tr[cur][v]=++tot;
			cur=tr[cur][v];
		}
		Len[cur]=len;
	}
	int que[max_tot],head,tail;
	inline void build()
	{
		head=1,tail=0;
		for(int i=0;i<4;++i)
		{
			int u=tr[0][i];
			if(u)
			{
				f[u]=Len[u];
				que[++tail]=u;
			}
		}
		while(head<=tail)
		{
//			fprintf(stderr,"head=%d tail=%d\n",head,tail);
			int u=que[head++];
			for(int i=0;i<4;++i)
			{
				int v=tr[u][i];
				if(v)
				{
					fail[v]=tr[fail[u]][i];
					f[v]=max(f[fail[v]],Len[v]);
					que[++tail]=v;
				}
				else
					tr[u][i]=tr[fail[u]][i];
			}
		}
	}
}
const int max_len=10+5;
char s[max_len];
const int max_n=1e3+5;
int dp[2][max_n][max_tot];
int main()
{
	int n=IO::read_int(),m=IO::read_int();
//	cerr<<"1\n";
	for(int i=1;i<=m;++i)
	{
		IO::read_string(s);
		AC::insert(s);
	}
//	cerr<<"2\n";
	AC::build();
//	cerr<<"3\n";
	dp[0][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		int x=(i-1)&1,y=i&1;
		for(int j=max(i-9,0);j<=i;++j)
			for(int k=0;k<=tot;++k)
				dp[y][j][k]=0;
		for(int j=max(i-10,0);j<=i-1;++j)
			for(int k=0;k<=tot;++k)
			{
//				if(dp[x][j][k])
//					fprintf(stderr,"dp[i][j][k]=%d (i=%d,j=%d,k=%d)\n",dp[x][j][k],i-1,j,k);
				if(dp[x][j][k])
				{
					for(int l=0;l<4;++l)
					{
						int Next=tr[k][l];
						if(f[Next]>=i-j)
						{
							add(dp[y][i][Next],dp[x][j][k]);
//							fprintf(stderr,"dp[%d][%d][%d]->dp[%d][%d][%d]\n",i-1,j,k,i,i,Next);
						}
						else
						{
							add(dp[y][j][Next],dp[x][j][k]);
//							fprintf(stderr,"dp[%d][%d][%d]->dp[%d][%d][%d]\n",i-1,j,k,i,j,Next);
						}
					}
				}
			}
	}
//	cerr<<"4\n";
	int x=n&1,ans=0;
	for(int k=0;k<=tot;++k)
		add(ans,dp[x][n][k]);
//	cerr<<"5\n";
	IO::write_int(ans);
	IO::write_char('\n');
	IO::flush();
	return 0;
}