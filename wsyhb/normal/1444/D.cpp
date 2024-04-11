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
const int max_cnt=1e3+5;
int l[max_cnt],p[max_cnt];
bool mark[max_cnt];
vector<int> a[2],b[2];
const int max_size=5e5+5;
bitset<max_size> f[2];
bool dp[max_size];
int val[max_size];
inline int cmp1(int x,int y)
{
	return abs(x)<abs(y); 
}
inline int cmp2(int x,int y)
{
	return abs(x)>abs(y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int h,v;
		scanf("%d",&h);
		for(int i=1;i<=h;++i)
			scanf("%d",l+i);
		scanf("%d",&v);
		for(int i=1;i<=v;++i)
			scanf("%d",p+i);
		if(h!=v)
		{
			printf("No\n");
			continue;
		}
		int sum1=0,sum2=0;
		for(int i=1;i<=h;++i)
			sum1+=l[i];
		for(int i=1;i<=v;++i)
			sum2+=p[i];
		if((sum1&1)||(sum2&1))
		{
			printf("No\n");
			continue;
		}
		random_shuffle(l+1,l+h+1);
		for(int i=0;i<=sum1;++i)
			f[0][i]=0;
		f[0][0]=1;
		int pos1=-1;
		for(int i=1;i<=h;++i)
		{
			int x=(i&1)^1,y=i&1;
			f[y]=f[x]|(f[x]<<l[i]);
			if(f[y][sum1>>1])
			{
				pos1=i;
				break;
			}
		}
		if(pos1==-1)
		{
			printf("No\n");
			continue;
		}
		random_shuffle(p+1,p+v+1);
		for(int i=0;i<=sum2;++i)
			f[0][i]=0;
		f[0][0]=1;
		int pos2=-1;
		for(int i=1;i<=v;++i)
		{
			int x=(i&1)^1,y=i&1;
			f[y]=f[x]|(f[x]<<p[i]);
			if(f[y][sum2>>1])
			{
				pos2=i;
				break;
			}
		}
		if(pos2==-1)
		{
			printf("No\n");
			continue;
		}
		a[0].clear(),a[1].clear();
		int tot1=sum1>>1;
		for(int i=1;i<=h;++i)
			mark[i]=false;
		for(int i=pos1+1;i<=h;++i)
		{
			a[0].push_back(l[i]);
			mark[i]=true;
			tot1-=l[i];
		}
		for(int i=0;i<=tot1;++i)
			dp[i]=false;
		dp[0]=true;
		for(int i=1;i<=pos1;++i)
			for(int j=tot1-l[i];j>=0;--j)
				if(dp[j]&&!dp[j+l[i]])
				{
					dp[j+l[i]]=true;
					val[j+l[i]]=i;
				}
		int now=tot1;
		while(now)
		{
			a[0].push_back(l[val[now]]);
			mark[val[now]]=true;
			now-=l[val[now]];
		}
		int cnt1=0;
		for(int i=1;i<=h;++i)
			if(!mark[i])
			{
				a[1].push_back(l[i]);
				++cnt1;
			}
		b[0].clear(),b[1].clear();
		int tot2=sum2>>1;
		for(int i=1;i<=v;++i)
			mark[i]=false;
		for(int i=pos2+1;i<=v;++i)
		{
			b[0].push_back(p[i]);
			mark[i]=true;
			tot2-=p[i];
		}
		for(int i=0;i<=tot2;++i)
			dp[i]=false;
		dp[0]=true;
		for(int i=1;i<=pos2;++i)
			for(int j=tot2-p[i];j>=0;--j)
				if(dp[j]&&!dp[j+p[i]])
				{
					dp[j+p[i]]=true;
					val[j+p[i]]=i;
				}
		now=tot2;
		while(now)
		{
			b[0].push_back(p[val[now]]);
			mark[val[now]]=true;
			now-=p[val[now]];
		}
		int cnt2=0;
		for(int i=1;i<=v;++i)
			if(!mark[i])
			{
				b[1].push_back(p[i]);
				++cnt2;
			}
		printf("Yes\n");
		int x=0,y=0;
		if(a[0].size()<a[1].size())
			swap(a[0],a[1]);
		if(b[0].size()>b[1].size())
			swap(b[0],b[1]);
		sort(a[1].begin(),a[1].end());
		sort(b[1].begin(),b[1].end(),greater<int>());
		while(a[1].size())
		{
			x+=a[1].back();
			printf("%d %d\n",x,y);
			y+=b[1].back();
			printf("%d %d\n",x,y);
			a[1].pop_back();
			b[1].pop_back();
		}
		while(b[1].size())
		{
			x-=a[0].back();
			printf("%d %d\n",x,y);
			y+=b[1].back();
			printf("%d %d\n",x,y);
			a[0].pop_back();
			b[1].pop_back();
		}
		sort(a[0].begin(),a[0].end());
		sort(b[0].begin(),b[0].end(),greater<int>());
		while(b[0].size())
		{
			x-=a[0].back();
			printf("%d %d\n",x,y);
			y-=b[0].back();
			printf("%d %d\n",x,y);
			a[0].pop_back();
			b[0].pop_back();
		}
	}
	return 0;
}