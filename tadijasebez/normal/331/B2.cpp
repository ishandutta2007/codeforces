#include <stdio.h>
#include <set>
using namespace std;
#define mp make_pair
const int N=300050;
struct BIT
{
	int sum[N];
	BIT(){ for(int i=0;i<N;i++) sum[i]=0;}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} Tree;
int a[N],b[N];
set<pair<int,int> > Set;
set<pair<int,int> >::iterator it;
void Cut(int x)
{
	it=Set.upper_bound(mp(x,N));
	it--;
	if(it->first==x || it->second<x) return;
	int l=it->first,r=it->second;
	Set.erase(*it);
	Tree.Set(x,1);
	Set.insert(mp(l,x-1));
	Set.insert(mp(x,r));
}
void Split(int x){ Cut(x);Cut(x+1);}
bool MergeLeft(set<pair<int,int> >::iterator it1)
{
	if(it1==Set.begin() || it1==Set.end()) return 0;
	set<pair<int,int> >::iterator it2;
	it2=it1;it1--;
	if(a[it1->second]<a[it2->first])
	{
		Tree.Set(it2->first,-1);
		int l=it1->first,r=it2->second;
		Set.erase(*it1);
		Set.erase(*it2);
		Set.insert(mp(l,r));
		return 1;
	}
	else return 0;
}
void Merge(int x)
{
	while(MergeLeft(--Set.lower_bound(mp(x,N))));
	while(MergeLeft(Set.lower_bound(mp(x,N))));
}
int main()
{
	int n,q,i,j,l,r,x,y,t;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&b[i]),a[b[i]]=i;
	for(i=1,j=1;i<=n;i=j)
	{
		for(j++;j<=n && a[j-1]<a[j];j++);
		Set.insert(mp(i,j-1));
		Tree.Set(i,1);
		//printf("(%i %i)\n",i,j-1);
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i %i",&l,&r),printf("%i\n",Tree.Get(l+1,r)+1);
		else
		{
			scanf("%i %i",&x,&y);
			if(x==y) continue;
			b[x]^=b[y];b[y]^=b[x];b[x]^=b[y];
			x=b[x];
			y=b[y];
			a[x]^=a[y];a[y]^=a[x];a[x]^=a[y];
			Split(x);
			Split(y);
			Merge(x);
			Merge(y);
		}
	}
	return 0;
}