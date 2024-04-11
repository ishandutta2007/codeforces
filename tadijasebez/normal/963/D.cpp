#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
const int N=200050;
const int S=317;
char s[N];
int tot,id[N],sa[N];
pair<pair<int,int> ,int> tmp[N];
void BuildSuffixArray()
{
	int i,j;
	s[++tot]='a'+26;
	for(i=1;i<=tot;i++) id[i]=s[i]-'a';
	for(j=0;j<20;j++)
	{
		for(i=1;i<=tot;i++) tmp[i]=mp(mp(id[i],id[i+(1<<j)]),i);
		sort(tmp+1,tmp+1+tot);
		int c=0;
		for(i=1;i<=tot;i++)
		{
			id[tmp[i].second]=c;
			c+=(i==tot || (tmp[i].first!=tmp[i+1].first));
		}
		if(c==tot) break;
	}
	for(i=1;i<=tot;i++) id[i]++;
	for(i=1;i<=tot;i++) sa[id[i]]=i;
}
int Search(int l, int r, int k, char c)
{
	int mid,ans=l-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(s[sa[mid]+k]<=c) l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}
struct Query
{
	int l,r,k,id,len;
	Query(){}
	bool operator < (Query b) const { return (r/S==b.r/S && l<b.l) || r/S<b.r/S;}
} Q[N];
int sol[N];
char t[N];
set<int> Set;
set<int>::iterator itl,itr;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int q,i,j,n;
	scanf("%s",s+1);
	tot=strlen(s+1);
	BuildSuffixArray();
	scanf("%i",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%i %s",&Q[i].k,t+1);
		n=strlen(t+1);
		int l=1,r=tot;
		for(j=1;j<=n;j++)
		{
			l=Search(l,r,j-1,t[j]-1)+1;
			r=Search(l,r,j-1,t[j]);
		}
		Q[i].id=i;
		Q[i].l=l;
		Q[i].r=r;
		Q[i].len=n;
		//if(n==0) printf("???\n");
		//if(Q[i].len==0) printf("???\n");
	}
	sort(Q+1,Q+1+q);
	int l=1,r=0;
	for(i=1;i<=q;i++)
	{
		if(Q[i].len==0) printf("%i %i %i %i %i???\n",Q[i].l,Q[i].r,Q[i].id,Q[i].k,Q[i].len);
		if(Q[i].l>Q[i].r)
		{
			sol[Q[i].id]=-1;
			continue;
		}
		if(r<Q[i].l || Q[i].r<l)
		{
			for(j=l;j<=r;j++) Set.erase(sa[j]);
			for(j=Q[i].l;j<=Q[i].r;j++) Set.insert(sa[j]);
			l=Q[i].l;
			r=Q[i].r;
		}
		while(Q[i].r>r) r++,Set.insert(sa[r]);
		while(Q[i].r<r) Set.erase(sa[r]),r--;
		while(Q[i].l>l) Set.erase(sa[l]),l++;
		while(Q[i].l<l) l--,Set.insert(sa[l]);
		if(Set.size()<Q[i].k) sol[Q[i].id]=-1;
		else
		{
			itl=itr=Set.begin();
			for(j=1;j<Q[i].k;j++) itr++;
			sol[Q[i].id]=N;
			while(itr!=Set.end())
			{
				sol[Q[i].id]=min(sol[Q[i].id],*itr-*itl+Q[i].len);
				itr++;
				itl++;
			}
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}