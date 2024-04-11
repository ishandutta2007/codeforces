#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
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
		flag=(c=='-'?true:flag);
		c=read_char();
	}
	int x=0;
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=read_char();
	}
	return flag?-x:x;
}
const int max_n=100+5;
int a[max_n][3][3];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=2;++j)
				for(int k=1;k<=2;++k)
					scanf("%d",&a[i][j][k]);
		if(m%2)
		{
			printf("NO\n");
			continue;
		}
		bool flag1=false;
		for(int i=1;i<=n;++i)
			if(a[i][1][2]==a[i][2][1])
			{
				flag1=true;
				break;
			}
		bool flag2=false;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(a[i][1][1]==a[j][1][1]&&a[i][1][2]==a[j][2][1]&&a[i][2][1]==a[j][1][2]&&a[i][2][2]==a[j][2][2])
				{
					flag2=true;
					break;
				}
		if(m==2)
			printf(flag1?"YES\n":"NO\n");
		else
			printf(flag1&&flag2?"YES\n":"NO\n");
	}
	return 0;
}