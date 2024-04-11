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
const int max_len=1e5+5;
char str[max_len];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str+1);
		int len=strlen(str+1);
		int ans=0; 
		for(int i=1;i<=len;++i)
		{
			if((i-1>=1&&str[i-1]==str[i])||(i-2>=1&&str[i-2]==str[i]))
			{
				for(char x='a';x<='z';++x)
				{
					if((i-1<1||str[i-1]!=x)&&(i-2<1||str[i-2]!=x)&&(i+1>len||str[i+1]!=x)&&(i+2>len||str[i+2]!=x))
					{
						str[i]=x;
						break;
					}
				}
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}