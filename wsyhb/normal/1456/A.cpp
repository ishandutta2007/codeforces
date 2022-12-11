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
int cnt[max_n];
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p,k,x,y;
		scanf("%d%d%d%s%d%d",&n,&p,&k,s+1,&x,&y);
		for(int i=0;i<k;++i)
			cnt[i]=0;
		for(int i=p;i<=n;++i)
			cnt[i%k]+=s[i]-'0';
		long long ans=1e18;
		for(int i=1;n-i+1>=p;++i)
		{
			long long res=(i-1)*y;
			int pos=i+p-1;
			int need=(n-pos)/k+1;
			int cnt_now=cnt[pos%k];
			res+=(need-cnt_now)*x;
			ans=min(ans,res);
			cnt[pos%k]-=s[pos]-'0';
//			fprintf(stderr,"i=%d pos=%d need=%d cnt_now=%d res=%lld\n",i,pos,need,cnt_now,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}