#include<bits/stdc++.h>
using namespace std;
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
        flag=(c=='-'?-1:flag);
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
	static char st[13];
	int head=0;
	while(x)
	{
		st[++head]=x%10+'0';
		x/=10;
	}
	while(head>0)
		putchar(st[head--]);
}
const int max_n=100+5;
char str[max_n];
int a[max_n][max_n];
struct node
{
	int X1,Y1,X2,Y2,X3,Y3;
	inline node(int x=1,int y=1,int p=1,int q=2,int c=2,int d=1)
	{
		X1=x,Y1=y,X2=p,Y2=q,X3=c,Y3=d;
	}
	void print()
	{
		printf("%d %d %d %d %d %d\n",X1,Y1,X2,Y2,X3,Y3);
	}
};
vector<node> ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",str+1);
			for(int j=1;j<=m;++j)
				a[i][j]=str[j]-'0';
		}
		ans.clear();
		for(int i=1;i<n;++i)
		{
			for(int j=1;j<m;++j)
			{
				if(a[i][j])
				{
					if(a[i][j+1])
					{
						ans.push_back(node(i,j,i,j+1,i+1,j));
						a[i][j]^=1,a[i][j+1]^=1,a[i+1][j]^=1; 
						++j;
					}
					else
					{
						ans.push_back(node(i,j,i+1,j,i+1,j+1));
						a[i][j]^=1,a[i+1][j]^=1,a[i+1][j+1]^=1;
					}
				}
			}
			if(a[i][m])
			{
				ans.push_back(node(i,m,i+1,m-1,i+1,m));
				a[i][m]^=1,a[i+1][m-1]^=1,a[i+1][m]^=1;
			}
		}
		for(int i=1;i<m;++i)
		{
			if(a[n][i])
			{
				ans.push_back(node(n-1,i,n-1,i+1,n,i));
				a[n][i]^=1;
				ans.push_back(node(n-1,i,n-1,i+1,n,i+1));
				a[n][i+1]^=1;
			}
		}
		if(a[n][m])
		{
			ans.push_back(node(n-1,m-1,n-1,m,n,m));
			ans.push_back(node(n-1,m,n,m-1,n,m));
			ans.push_back(node(n-1,m-1,n,m-1,n,m));
		}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<int(ans.size());++i)
			ans[i].print();
	}
	return 0;
}