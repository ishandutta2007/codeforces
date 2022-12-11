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
	int read_int()
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
const int max_len=1e5+5;
char s[max_len];
int pre[max_len][2],suf[max_len][2];
const int max_cnt=1e5+5;
int id[max_cnt];
long long Pre[max_len],Suf[max_len];
int main()
{
	int x,y;
	scanf("%s%d%d",s+1,&x,&y);
	int n=strlen(s+1);
	if(x<y)
	{
		swap(x,y);
		reverse(s+1,s+n+1);
	}
//	printf("x=%d y=%d %s\n",x,y,s+1);
	for(int i=1;i<=n;++i)
	{
		pre[i][0]=pre[i-1][0];
		pre[i][1]=pre[i-1][1];
		if(s[i]!='?')
			++pre[i][s[i]-'0'];
//		printf("i=%d cnt0=%d cnt1=%d\n",i,pre[i][0],pre[i][1]);
	}
	for(int i=n;i>=1;--i)
	{
		suf[i][0]=suf[i+1][0];
		suf[i][1]=suf[i+1][1];
		if(s[i]!='?')
			++suf[i][s[i]-'0'];
//		printf("i=%d cnt0=%d cnt1=%d\n",i,suf[i][0],suf[i][1]);
	}
	long long cnt_before=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
			cnt_before+=suf[i+1][1];
	}
//	printf("%lld\n",cnt_before);
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='?')
			id[++cnt]=i;
	}
//	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
	{
		Pre[i]=Pre[i-1];
		Pre[i]+=pre[id[i]-1][0];
//		printf("i=%d Pre[i]=%lld\n",i,Pre[i]);
	}
	for(int i=cnt;i>=1;--i)
	{
		Suf[i]=Suf[i+1];
		Suf[i]+=suf[id[i]+1][1];
//		printf("i=%d Suf[i]=%lld\n",i,Suf[i]);
	}
	long long ans=1e18;
	for(int i=0;i<=cnt;++i)
	{
		long long cnt_now=cnt_before+Pre[i]+Suf[i+1];
		long long cnt_all=1ll*(pre[n][1]+i)*(pre[n][0]+cnt-i);
//		printf("i=%d cnt_now=%lld cnt_all=%lld\n",i,cnt_now,cnt_all);
		ans=min(ans,cnt_now*x+(cnt_all-cnt_now)*y);
	}
	printf("%lld\n",ans);
	return 0;
}