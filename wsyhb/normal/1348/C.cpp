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
char s[max_n];
string str[max_n],S,ans;
int Size[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d%s",&n,&k,s+1);
		sort(s+1,s+n+1);
		for(int i=1;i<=k;++i)
		{
			str[i]=string("")+s[i];
			Size[i]=1;
		}
		ans=string("")+s[k];
		for(int i=k+1;i<=n;++i)
			ans+=s[i];
		int now=k;
		bool Flag=false;
		while(now<n)
		{
			bool flag=false;
			for(int i=1;i<k;++i)
			{
				if(str[i][Size[i]-1]!=str[i+1][Size[i+1]-1])
				{
					flag=true;
					break;
				}
			}
			if(flag)
			{
				char Max='a';
				int id=0;
				for(int i=1;i<=k;++i)
				{
					if(str[i][Size[i]-1]>=Max)
					{
						Max=str[i][Size[i]-1];
						id=i;
					}
				}
				ans=min(ans,str[id]);
				Flag=true;
				break;
			}
			for(int i=1;i<=k;++i)
			{
				if(now<n)
				{
					str[i]+=s[++now];
					++Size[i];
				}
				else
					break;
			}
		}
		if(!Flag)
		{
			string Max="";
			for(int i=1;i<=k;++i)
				Max=max(Max,str[i]);
			ans=min(ans,Max);
		}
		cout<<ans<<endl;
	}
	return 0;
}