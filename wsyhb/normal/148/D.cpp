#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
bool flag_EOF;
inline char read_char()
{
	if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
	return S!=T?*(S++):EOF;
}
inline int read_int()
{
	bool flag=false;
	char c=read_char();
	while(c<'0'||c>'9')
	{
		if(c==EOF)
		{
			flag_EOF=true;
			return 0;
		}
		flag=(c=='-'?true:flag);
		c=read_char();
	}
	int x=0;
	while(c>='0'&&c<='9')
	{
		x=x*10+(c^48);
		c=read_char();
	}
	return flag?-x:x;
}
const int max_w=1e3+5;
const int max_b=1e3+5;
double dp[2][max_w][max_b]; 
int main()
{
	int w=read_int(),b=read_int();
	for(int i=0;i<=w;++i)
		for(int j=0;j<=b;++j)
			if(i||j)
			{
				dp[0][i][j]+=1.0*i/(i+j);
				if(j>=1)
					dp[0][i][j]+=1.0*j/(i+j)*dp[1][i][j-1];
				if(j>=2)
					dp[1][i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*dp[0][i][j-2];
				if(i>=1&&j>=1)
					dp[1][i][j]+=1.0*j/(i+j)*i/(i+j-1)*dp[0][i-1][j-1];
			}
	printf("%.11lf",dp[0][w][b]);
	return 0;
}