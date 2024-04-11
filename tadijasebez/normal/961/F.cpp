#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=1000005;
char s[N];
int tot,sa[N],id[N];
pair<pair<int,int> ,int> tmp[N];
//vector<int> Block[N][2];
bool comp(int i, int j){ return id[i]<id[j];}
void BuildSuffixArray()
{
	int i,j;
	s[++tot]='a'+26;
	for(i=1;i<=tot;i++) id[i]=s[i]-'a';
	for(j=0;j<22;j++)
	{
		for(i=1;i<=tot;i++)
		{
			tmp[i].second=i;
			tmp[i].first.first=id[i];
			tmp[i].first.second=i+(1<<j)<N?id[i+(1<<j)]:0;
		}
		sort(tmp+1,tmp+1+tot);
		int c=0;
		for(i=1;i<=tot;i++)
		{
			id[tmp[i].second]=c+1;
			c+=(i==tot)||(tmp[i].first!=tmp[i+1].first);
		}
		if(c==tot) break;
	}
	for(i=1;i<=tot;i++) sa[id[i]]=i;
}
/*void BuildSuffixArray()
{
	int i,j,k;
	s[++tot]='a'+26;
	for(i=1;i<=tot;i++) id[i]=s[i]-'a',sa[i]=i;
	sort(sa+1,sa+1+tot,comp);
	for(j=0;j<22;j++)
	{
		for(i=1;i<=tot;i++)
		{
			if(sa[i]<=1<<j) continue;
			Block[id[sa[i]-(1<<j)]][0].pb(sa[i]-(1<<j));
			Block[id[sa[i]-(1<<j)]][1].pb(id[sa[i]]);
		}
		for(i=1;i<=tot;i++)
		{
			if(sa[i]+(1<<j)>tot)
			{
				Block[id[sa[i]]][0].pb(sa[i]);
				Block[id[sa[i]]][1].pb(0);
			}
		}
		int c=0,sz=0;
		for(i=0;i<=tot;i++)
		{
			for(k=0;k<Block[i][0].size();k++)
			{
				sa[++sz]=Block[i][0][k];
				id[sa[sz]]=c+1;
				c+=(k+1==Block[i][0].size())||(Block[i][1][k]!=Block[i][1][k+1]);
			}
			Block[i][0].clear();
			Block[i][1].clear();
		}
		if(c==tot) break;
	}
}*/
int lcp[N];
void BuildLCPArray()
{
	int k=0,i,j;
	for(i=1;i<=tot;i++)
	{
		if(id[i]==tot) k=0;
		else
		{
			j=sa[id[i]+1];
			while(i+k<=tot && j+k<=tot && s[i+k]==s[j+k]) k++;
			lcp[id[i]]=k;
			if(k) k--;
		}
	}
}
int min(int a, int b){ return a>b?b:a;}
int rmq[N][20],logs[N];
void BuildSparseTable()
{
	int i,j;
	for(i=2;i<N;i++) logs[i]=logs[i>>1]+1;
	for(i=1;i<=tot;i++) rmq[i][0]=lcp[i];
	for(j=1;j<20;j++)
	{
		for(i=1;i<=tot-(1<<j)+1;i++)
		{
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
		}
	}
}
int LCP(int l, int r)
{
	l=id[l];
	r=id[r];
	if(l>r) l^=r,r^=l,l^=r;
	if(l==r) return tot;
	r--;
	int k=logs[r-l+1];
	return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
int sol[N],n;
int max(int a, int b){ return a>b?a:b;}
void Add(int x)
{
	int l=x,r=n-x+1;
	int top=x-1,bot=0,mid,ans=-1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		//printf("%i %i\n",mid,LCP(l-mid,r-mid));
		if(LCP(l-mid,r-mid)>=mid*2+1) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	//printf("ANS:%i %i\n",x,ans);
	if(ans!=-1) sol[x-ans]=max(sol[x-ans],ans*2+1);
}
int main()
{
	int i;
	scanf("%i",&n);
	scanf("%s",s+1);
	tot=n;
	BuildSuffixArray();
	BuildLCPArray();
	BuildSparseTable();
	//printf("Suffix Array:\n");
	//for(i=1;i<=n;i++) printf("%i ",sa[i]);
	//printf("\n");
	//printf("LCP Array:\n");
	//for(i=1;i<=n;i++) printf("%i ",lcp[i]);
	//printf("\n");
	for(i=1;i<=(n+1)/2;i++) sol[i]=-1;
	for(i=1;i<=n/2;i++) Add(i);
	for(i=1;i<=(n+1)/2;i++)
	{
		sol[i]=max(sol[i],sol[i-1]-2);
		printf("%i ",sol[i]);
	}
	return 0;
}