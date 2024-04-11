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
            if(x==EOF)
            {
                flag_EOF=true;
                return;
            }
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
        pw=0;
    }
    inline void write_char(char x)
    {
        if(pw==buffer_size)
            flush();
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
    inline void write_double(double x,int cnt_digits,bool mark=true)
	{
		if(x<0)
		{
			write_char('-');
			x=-x;
		}
		if(mark)
		{
			double eps=0.1;
			for(int i=1;i<=cnt_digits;++i)
				eps*=0.1;
			x+=5*eps;
		}
		write_int(int(x));
		write_char('.');
		for(int i=1;i<=cnt_digits;++i)
		{
			x-=int(x);
			x*=10;
			write_char(int(x)+'0');
		}
	}
}
const int max_n=1e5+5;
int x[max_n],y[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cx=0,cy=0;
		for(int i=1;i<=2*n;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(b==0)
				x[++cx]=a>0?a:-a;
			else
				y[++cy]=b>0?b:-b;
		}
		assert(cx==n&&cy==n);
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		double ans=0;
		for(int i=1;i<=n;++i)
			ans+=sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]);
		printf("%.12lf\n",ans);
	}
	IO::flush();
    return 0;
}