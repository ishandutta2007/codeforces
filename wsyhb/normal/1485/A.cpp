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
inline bool check(int a,int n,int p)
{
    int res=1;
    for(int i=1;i<=n;++i)
    {
    	if(1ll*res*a>=p)
    		return true;
    	res*=a;
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int ans=1e9;
		for(int i=1;i<=32;++i)
		{
			int L=2,R=1e9+1,mid,res=1e9;
			while(L<=R)
			{
				mid=(L+R)>>1;
				if(check(mid,i,a+1))
					res=mid,R=mid-1;
				else
					L=mid+1;
			}
			ans=min(ans,i+max(res-b,0));
		}
		printf("%d\n",ans);
	} 
    return 0;
}