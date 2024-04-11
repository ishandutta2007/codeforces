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
int n,m;
const int max_n=5e5+5;
const int max_m=5e5+5;
int power[max_m];
int f[max_m],sz[max_m];
vector<int> id[max_m];
inline void init()
{
	for(int i=1;i<=m;++i)
		f[i]=i,sz[i]=1;
	power[0]=1;
	for(int i=1;i<=m;++i)
		power[i]=(power[i-1]<<1)%P;
}
int get_fa(int x)
{
	return f[x]!=x?f[x]=get_fa(f[x]):x;
}
inline bool merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y&&(id[x].empty()||id[y].empty()))
	{
		if(id[x].size()>id[y].size())
			swap(x,y);
		while(id[x].size())
		{
			id[y].push_back(id[x].back());
			id[x].pop_back();
		}
		f[x]=y;
		sz[y]+=sz[x];
		sz[x]=0;
		return true;
	}
	return false;
}
vector<int> ans;
int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		if(k==1)
		{
			int x;
			scanf("%d",&x);
			id[get_fa(x)].push_back(i);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(merge(x,y))
				ans.push_back(i);
		}
	}
	int Ans=1;
	for(int i=1;i<=m;++i)
	{
		if(get_fa(i)!=i)
			continue;
		if(id[i].size())
		{
			Ans=1ll*Ans*power[sz[i]]%P;
			int Min=1e9;
			for(int j=0;j<int(id[i].size());++j)
				Min=min(Min,id[i][j]);
			ans.push_back(Min);
		}
		else
			Ans=1ll*Ans*power[sz[i]-1]%P;
	}
	sort(ans.begin(),ans.end());
	printf("%d %d\n",Ans,int(ans.size()));
	for(int i=0;i<int(ans.size());++i)
		printf("%d%c",ans[i],i+1<int(ans.size())?' ':'\n');
	return 0;
}