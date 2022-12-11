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
const int P=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=P?P:0);
}
inline void sub(int &a,int b)
{
	a=a-b+(a-b<0?P:0);
}
inline void mul(int &a,int b)
{
	a=1ll*a*b%P;
}
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=P?P:0);
}
inline int get_dif(int a,int b)
{
	return a-b+(a-b<0?P:0);
}
inline int get_pro(int a,int b)
{
	return 1ll*a*b%P;
}
int A[32],B[32],C[32];
int dp[32][2][2][2],sum[32][2][2][2];
int solve(int x,int y,int k)
{
	if(x<0||y<0||k<0)
		return 0;
	for(int i=0;i<=30;++i)
	{
		A[i]=x&1,x>>=1;
		B[i]=y&1,y>>=1;
		C[i]=k&1,k>>=1;
	}
	reverse(A,A+31);
	reverse(B,B+31);
	reverse(C,C+31);
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	dp[0][1][1][1]=1;
	sum[0][1][1][1]=0;
	for(int i=0;i<=30;++i)
		for(int a=0;a<=1;++a)
			for(int b=0;b<=1;++b)
				for(int c=0;c<=1;++c)
					for(int x=0;x<=1;++x)
						for(int y=0;y<=1;++y)
						{
							int z=x^y;
							if(a==1&&x>A[i])
								continue;
							if(b==1&&y>B[i])
								continue;
							if(c==1&&z>C[i])
								continue;
							add(dp[i+1][a&(A[i]==x)][b&(B[i]==y)][c&(C[i]==z)],dp[i][a][b][c]);
							add(sum[i+1][a&(A[i]==x)][b&(B[i]==y)][c&(C[i]==z)],sum[i][a][b][c]);
							add(sum[i+1][a&(A[i]==x)][b&(B[i]==y)][c&(C[i]==z)],get_pro(z<<(30-i),dp[i][a][b][c]));
						}
	int res=0;
	for(int a=0;a<=1;++a)
		for(int b=0;b<=1;++b)
			for(int c=0;c<=1;++c)
				add(res,get_sum(dp[31][a][b][c],sum[31][a][b][c]));
	return res;
}
int main()
{
	int q=IO::read_int();
	while(q--)
	{
		int X1=IO::read_int()-1,Y1=IO::read_int()-1,X2=IO::read_int()-1,Y2=IO::read_int()-1,k=IO::read_int()-1;
		int ans=get_sum(solve(X1-1,Y1-1,k),solve(X2,Y2,k));
		sub(ans,get_sum(solve(X1-1,Y2,k),solve(X2,Y1-1,k)));
		printf("%d\n",ans);
	}
	return 0;
}