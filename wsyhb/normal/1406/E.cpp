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
const int max_n=1e5+5;
bool prime_mark[max_n],vis[max_n];
int prime[max_n],cnt;
vector<int> mul;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		if(!prime_mark[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt&&1ll*i*prime[j]<=n;++j)
		{
			prime_mark[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
	int k=sqrt(cnt);
	int num=n;
	int ans=1;
	bool flag=false;
	for(int i=1;i<=cnt;++i)
	{
		int cnt_now=0;
		int x=prime[i];
		for(int j=x;j<=n;j+=x)
			if(!vis[j])
			{
				++cnt_now,--num;
				vis[j]=true;
			}
		printf("B %d\n",x);
		fflush(stdout);
		int ret;
		scanf("%d",&ret);
		if(ret!=cnt_now)
		{
			mul.clear();
			for(long long j=x;j<=n;j*=x)
				mul.push_back(j);
			int l=0,r=mul.size()-1,mid,res=0;
			while(l<=r)
			{
				mid=(l+r)>>1;
				printf("A %d\n",mul[mid]);
				fflush(stdout);
				int ret;
				scanf("%d",&ret);
				if(ret) res=mid,l=mid+1;
				else r=mid-1;
			}
			ans*=mul[res];
		}
		if((i==cnt||i%k==0)&&!flag)
		{
			printf("A 1\n");
			fflush(stdout);
			int ret;
			scanf("%d",&ret);
			if(ret!=num)
			{
				for(int j=(i-1)/k*k+1;j<=i&&!flag;++j)
					for(long long v=prime[j];v<=n;v*=prime[j])
					{
						printf("A %lld\n",v);
						fflush(stdout);
						int ret;
						scanf("%d",&ret);
						if(ret) ans*=prime[j],flag=true;
						else break;
					}
			}
		}
	}
	printf("C %d\n",ans);
	fflush(stdout);
	return 0;
}