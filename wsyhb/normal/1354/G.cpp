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
const int max_n=1e3+5;
bool vis[max_n];
char str[10];
int main()
{
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			vis[i]=false;
		bool flag=false;//if no.1 is a gift
		for(int t=1;t<=30&&t<=n-1;++t)
		{
			int x;
			do
			{
				x=rand()%(n-1)+2;
			}while(vis[x]);
			vis[x]=true;
			puts("? 1 1");
			puts("1");
			printf("%d\n",x);
			fflush(stdout);
			scanf("%s",str);
			if(str[0]=='S')
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			puts("! 1");
			fflush(stdout);
			continue;
		}
		int now=1;
		while((now<<1)<n)
		{
			printf("? %d %d\n",now,now);
			for(int i=1;i<=now;++i)
				printf("%d%c",i,i<now?' ':'\n');
			for(int i=1;i<=now;++i)
				printf("%d%c",i+now,i<now?' ':'\n');
			fflush(stdout);
			scanf("%s",str);
			if(str[0]=='F')
				break;
			now<<=1;
		}
		int L=1,R=min(now,n-now),mid,ans=now;
		while(L<=R)
		{
			mid=(L+R)>>1;
			printf("? %d %d\n",mid,mid);
			for(int i=1;i<=mid;++i)
				printf("%d%c",i,i<mid?' ':'\n');
			for(int i=1;i<=mid;++i)
				printf("%d%c",i+now,i<mid?' ':'\n');
			fflush(stdout);
			scanf("%s",str);
			if(str[0]=='F')
				ans=mid,R=mid-1;
			else
				L=mid+1;
		}
		printf("! %d\n",ans+now);
		fflush(stdout);
	}
	return 0;
}