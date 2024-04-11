#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buf_size=1<<20;
    char buf[buf_size],*S,*T;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buf_size,stdin);
        return S!=T?*(S++):EOF;
    }
    bool flag_EOF;
    inline int read_int()
    {
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            if(c==EOF)
            {
                flag_EOF=true;
                return 0;
            }
            neg=(c=='-');
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^48);
            c=read_char();
        }
        return neg?-x:x;
    }
    inline void read_string(char *s)
    {
        char c=read_char();
        while(c<'a'||c>'z')
        {
            if(c==EOF)
            {
                flag_EOF=true;
                return;
            }
            c=read_char();
        }
        while(c>='a'&&c<='z')
        {
            *(s++)=c;
            c=read_char();
        }
        *s='\0';
    }
    inline double read_double()
    {
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            if(c==EOF)
            {
                flag_EOF=true;
                return 0;
            }
            neg=(c=='-');
            c=read_char();
        }
        double x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^48);
            c=read_char();
        }
        if(c=='.')
        {
            c=read_char();
            double eps=1;
            while(c>='0'&&c<='9')
            {
                eps*=0.1;
                x+=eps*(c^48);
                c=read_char();
            }
        }
        return neg?-x:x;
    }
    char fw[buf_size];
    int pw;
    inline void flush()
    {
        fwrite(fw,1,pw,stdout);
        pw=0;
    }
    inline void write_char(char x)
    {
        if(pw==buf_size)
            flush();
        fw[pw++]=x;
    }
    char st[26];
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
            st[++top]=x%10^48;
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
            x+=5*pow(0.1,cnt_digits+1);
        write_int(int(x));
        if(cnt_digits>0)
        {
            write_char('.');
            for(int i=1;i<=cnt_digits;++i)
            {
                x-=int(x),x*=10;
                write_char(int(x)^48);
            }
        }
    }
}
const int max_n=5e3+5;
const int max_m=5e3+5;
char A[max_n],B[max_m];
int dp[max_n][max_m];
int main()
{
	int n,m;
	scanf("%d%d%s%s",&n,&m,A+1,B+1);
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(A[i]==B[j])
				dp[i][j]=2;
			else
				dp[i][j]=-1e9;
			if(i>1)
				dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
			if(j>1)
				dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			if(i>1&&j>1&&A[i]==B[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			ans=max(ans,dp[i][j]);
		}
	printf("%d\n",ans);
    IO::flush();
    return 0;
}