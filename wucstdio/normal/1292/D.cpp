#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5000;
int prime[5010],tot;//tot:669
bool vis[5010];
int cnt[5010][810];
int d[5010],D[5010];
void init()
{
	for(int i=2;i<=N;i++)
		if(!vis[i]){
			prime[++tot]=i;
			for(int j=i;j<=N;j+=i)
			{
				int tmp=j;
				while(tmp%i==0)tmp/=i,cnt[j][tot]++;
				if(j!=i)vis[j]=true;
			}
		}
	for(int i=2;i<=N;i++)
		for(int j=1;j<=tot;j++)
			cnt[i][j]+=cnt[i-1][j];
	for(int i=1;i<=N;i++)
	{
		d[i]=D[i]=0;
		for(int j=tot;j>=1;j--)
			D[i]+=cnt[i][j];
		if(i>1){
			for(int j=tot;j>=1;j--)
			{
				if(cnt[i][j]!=cnt[i-1][j]){
					d[i]+=cnt[i-1][j];
					break;
				}
				d[i]+=cnt[i][j];
			}
		}
	}
//	cerr<<tot<<"\n";
	return ;
}
long long ans;
int w[5010],f[5010];
long long g[5010];
int n;
int Sum(int l,int r)
{
	return f[r]-f[l-1];
}
long long SSum(int l,int r)
{
	return g[r]-g[l-1];
}
void work(int l,int r,int now,long long cursum)
{
	long long sum=cursum+SSum(l,r)-(long long)now*Sum(l,r);
	ans=min(ans,sum);
	if(l==r)return ;
	int mn=D[l],pos=l;
	for(int i=l+1;i<=r;i++)
	{
		if(d[i]==now){
			work(pos,i-1,mn,cursum+(long long)(mn-now)*(n-Sum(pos,i-1))+SSum(l,pos-1)+SSum(i,r)-(long long)now*(Sum(l,pos-1)+Sum(i,r)));
			mn=D[i];pos=i;
		}
		else mn=min(mn,d[i]);
	}
	work(pos,r,mn,cursum+(long long)(mn-now)*(n-Sum(pos,r))+SSum(l,pos-1)-(long long)now*Sum(l,pos-1));
	return ;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		w[x]++;
	}
	for(int i=1;i<=N;i++)
	{
		f[i]=f[i-1]+w[i];
		g[i]=g[i-1]+(long long)w[i]*D[i];
	}
	ans=1e18;
	work(1,N,0,0);
	printf("%I64d\n",ans);
	return 0;
}