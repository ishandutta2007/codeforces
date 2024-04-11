#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
long long a[max_n];
const int max_m=1e5+5;
vector<int> s[max_m];
int size[max_m];
long long add[max_m],sum[max_m];
const int max_block=316+5;
int id[max_block],cnt[max_block][max_m];
bool mark[max_m],flag[max_block][max_n];
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	int block=sqrt(n/500);
	int tot_set=0;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",size+i);
		mark[i]=(size[i]>block);
		s[i].resize(size[i]);
		for(int j=0;j<size[i];++j) scanf("%d",&s[i][j]);
		if(mark[i])
		{
			id[++tot_set]=i;
			for(int j=0;j<size[i];++j)
			{
				flag[tot_set][s[i][j]]=true;
				sum[i]+=a[s[i][j]];
			}
		}
	}
	for(int i=1;i<=m;++i)
		for(int j=0;j<size[i];++j)
			for(int k=1;k<=tot_set;++k)
				cnt[k][i]+=flag[k][s[i][j]];
	for(int i=1;i<=q;++i)
	{
		static char op[3];
		scanf("%s",op);
		if(op[0]=='?')
		{
			int k;
			scanf("%d",&k);
			if(mark[k]) printf("%lld\n",sum[k]);
			else
			{
				long long ans=0;
				for(int j=0;j<size[k];++j)
					ans+=a[s[k][j]];
				for(int j=1;j<=tot_set;++j)
					ans+=1ll*cnt[j][k]*add[id[j]];
				printf("%lld\n",ans);
			}
		}
		else
		{
			int k,x;
			scanf("%d%d",&k,&x);
			if(mark[k])
			{
				add[k]+=x;
				for(int j=1;j<=tot_set;++j)
					sum[id[j]]+=1ll*cnt[j][k]*x;
			}
			else
			{
				for(int j=0;j<size[k];++j)
					a[s[k][j]]+=x;
				for(int j=1;j<=tot_set;++j)
					sum[id[j]]+=1ll*cnt[j][k]*x;
			}
		}
	}
	return 0;
}