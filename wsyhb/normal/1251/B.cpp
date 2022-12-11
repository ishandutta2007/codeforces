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
const int max_len=50+5;
char s[max_len];
const int max_n=50+5;
int len[max_n];
int cnt[2];
int main()
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int n;
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);
			len[i]=strlen(s+1);
			for(int j=1;j<=len[i];++j)
				++cnt[s[j]-'0'];
		}
		sort(len+1,len+n+1);
		int tot=(cnt[0]>>1)+(cnt[1]>>1);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(len[i]/2<=tot)
			{
				tot-=len[i]/2;
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}