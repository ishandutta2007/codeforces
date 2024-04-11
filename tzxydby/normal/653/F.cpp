#include <bits/stdc++.h>
using namespace std;
const int N=500050,M=2*N;
vector<int> pos[M];
int FindL(int j,int x){return lower_bound(pos[j].begin(),pos[j].end(),x)-pos[j].begin()+1;}
int FindR(int j,int x){return upper_bound(pos[j].begin(),pos[j].end(),x)-pos[j].begin();}
char s[N];
pair<pair<int,int>,int> tmp[N];
int sa[N],id[N],lcp[N],tot;
void Build()
{
	s[++tot]='a'+26;
	for(int i=1;i<=tot;i++) 
		id[i]=s[i]-'a';
	for(int j=1;1;j<<=1)
	{
		for(int i=1;i<=tot;i++) 
			tmp[i]=make_pair(make_pair(id[i],i+j<=tot?id[i+j]:0),i);
		sort(tmp+1,tmp+1+tot);
		int c=0;
		for(int i=1;i<=tot;i++)
		{
			id[tmp[i].second]=c+1;
			c+=(i==tot)||(tmp[i].first!=tmp[i+1].first);
		}
		if(c==tot) 
			break;
	}
	for(int i=1;i<=tot;i++) 
		sa[id[i]]=i;
	int k=0;
	for(int i=1;i<=tot;i++)
	{
		if(id[i]!=tot)
		{
			int j=sa[id[i]+1];
			while(max(i,j)+k<=tot&&s[i+k]==s[j+k]) 
				k++;
			lcp[id[i]]=k;
			if(k) k--;
		}
	}
}
int sum[N];
int main()
{
	int n,i;
	scanf("%d",&n);
	scanf("%s",s+1);
	n=tot=strlen(s+1);
	Build();
	for(i=1;i<=n;i++) 
		sum[i]=sum[i-1]+(s[i]=='('?1:-1),pos[sum[i]+N].push_back(i);
	long long ans=0;
	for(i=1;i<=tot;i++)
	{
		int l=sa[i]+lcp[i-1];
		int r=FindR(sum[sa[i]-1]-1+N,sa[i]-1);
		if(r==pos[sum[sa[i]-1]-1+N].size()) 
			r=n;
		else 
			r=pos[sum[sa[i]-1]-1+N][r]-1;
		ans+=max(FindR(sum[sa[i]-1]+N,r)-FindL(sum[sa[i]-1]+N,l)+1,0);
	}
	printf("%lld\n",ans);
	return 0;
}