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
const int max_n=75+5;
int a[max_n],b[max_n];
struct node
{
	int a,b,id;
}p[max_n];
inline bool cmp(const node &x,const node &y)
{
	return x.b<y.b;
}
int f[max_n][max_n];
bool mark[max_n][max_n];
bool use[max_n];
vector<int> ans;
int st[max_n],_top;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d%d",a+i,b+i);
		int Ans=0;
		ans.clear();
		for(int i=1;i<=n;++i)
		{
			int now=a[i]+b[i]*(k-1);
			for(int j=1;j<=n-1;++j)
				p[j].a=a[j],p[j].b=b[j],p[j].id=j;
			p[i].a=a[n],p[i].b=b[n],p[i].id=n;
			sort(p+1,p+n,cmp);
			memset(f,128,sizeof(f));
			f[0][0]=0;
			for(int x=1;x<=n-1;++x)
				for(int y=0;y<=k-1&&y<=x;++y)
				{
					f[x][y]=f[x-1][y]+p[x].b*(k-1);
					mark[x][y]=false;
					if(y>0)
					{
						int v=f[x-1][y-1]+p[x].a+p[x].b*(y-1);
						if(v>f[x][y])
						{
							f[x][y]=v;
							mark[x][y]=true;
						}
					}
				}
			now+=f[n-1][k-1];
			if(now>Ans)
			{
				Ans=now;
				ans.clear();
				for(int j=1;j<=n;++j)
					use[j]=false;
				int x_now=n-1,y_now=k-1;
				while(x_now||y_now)
				{
					if(mark[x_now][y_now])
					{
						use[p[x_now].id]=true;
						st[++_top]=p[x_now].id;
						--x_now,--y_now;
					}
					else
						--x_now;
				}
				while(_top>0)
					ans.push_back(st[_top--]);
				use[i]=true;
				for(int j=1;j<=n;++j)
				{
					if(!use[j])
					{
						ans.push_back(j);
						ans.push_back(-j);
					}
				}
				ans.push_back(i);
			}
		}
		printf("%d\n",int(ans.size()));
		for(int i=0;i<int(ans.size());++i)
			printf("%d%c",ans[i],i+1<int(ans.size())?' ':'\n');
	}
	return 0;
}