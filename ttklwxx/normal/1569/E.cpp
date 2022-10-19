#include<iostream>
#include<cstdio>
#include<map>
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int p[105];
int pos[5][105];
int a,h,tk,yo,zc;
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
void dfs4(int k);
void dfsjm4(int k,int wz)
{
	if(wz==(1<<(k-1))+1)
	{
		dfs4(k-1);
		return;
	}
	p[pos[k][wz*2-1]]=(1<<(k-1))+1;
	pos[k-1][wz]=pos[k][2*wz]; 
	dfsjm4(k,wz+1); 
	p[pos[k][wz*2]]=(1<<(k-1))+1;
	pos[k-1][wz]=pos[k][2*wz-1];
	dfsjm4(k,wz+1); 
}
void dfs4(int k)
{
	if(k==0)
	{
		p[pos[0][1]]=1;
		int ans=0;
		for(int i=1;i<=(1<<tk);i++)
		{
			ans=(ans+1LL*i*ksm(a,p[i])%mod)%mod;
		}
		if(ans==h)
		{
			for(int i=1;i<=(1<<tk);i++)
			{
				printf("%d ",p[i]);
			}
			printf("\n");
			exit(0);
		}
		return;
	}
	dfsjm4(k,1);
}
int tans[100005][33],cnt;
map<int,int>ma;
void dfs5(int k);
void dfsjm5(int k,int wz)
{
	if(wz==(1<<(k-1))+1)
	{
		dfs5(k-1);
		return;
	}
	p[pos[k][wz*2-1]]=(1<<(k))+1;
	pos[k-1][wz]=pos[k][2*wz]; 
	dfsjm5(k,wz+1); 
	p[pos[k][wz*2]]=(1<<(k))+1;
	pos[k-1][wz]=pos[k][2*wz-1];
	dfsjm5(k,wz+1); 
}
void dfs5(int k)
{
	if(k==0)
	{
		if(yo)p[pos[0][1]]=1;
		else p[pos[0][1]]=2;
		int ans=0;
		if(zc)
		{
			for(int i=1;i<=16;i++)
			{
				ans=(ans+1LL*i*ksm(a,p[i])%mod)%mod;
				//printf("%d ",p[i]);
			}
			//printf("\n");
			++cnt;
			ma[ans]=cnt;
			for(int i=1;i<=16;i++)tans[cnt][i]=p[i];
			return;
		}
		else
		{
			for(int i=17;i<=32;i++)
			{
				ans=(ans+1LL*i*ksm(a,p[i-16])%mod)%mod;
				//printf("%d ",p[i-16]);
			}
			//printf("\n");
			if(ma[(h-ans+mod)%mod]!=0)
			{
				int x=ma[(h-ans+mod)%mod];
				for(int i=1;i<=16;i++)
				{
					printf("%d ",tans[x][i]);
				}
				for(int i=17;i<=32;i++)printf("%d ",p[i-16]);
				printf("\n");
				exit(0);
			}
		}
		return;
	}
	dfsjm5(k,1);
}
int main()
{
	tk=read();
	a=read();
	h=read();
	if(tk<=4)
	{
		for(int i=1;i<=(1<<tk);i++)pos[tk][i]=i;
		dfs4(tk);
		printf("-1\n");
		return 0;
	}
	yo=0;
	for(int i=1;i<=16;i++)pos[4][i]=i;
	zc=1;
	dfs5(4);
	yo=1;
	zc=0;
	dfs5(4);
	cnt=0;
	ma.clear();
	yo=1;
	for(int i=1;i<=16;i++)pos[4][i]=i;
	zc=1;
	dfs5(4);
	yo=0;
	zc=0;
	dfs5(4);
	printf("-1\n");
	return 0;
}