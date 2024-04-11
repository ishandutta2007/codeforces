#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
int l[N],r[N],h[N];
struct SegmentTree
{
	vector<int> mx;
	int sz;
	SegmentTree(){}
	void init(int n){ sz=n,mx.resize(2*n);}
	void Set(int l, int r, int h)
	{
		for(l+=sz,r+=sz;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) mx[l]=max(mx[l],h),l++;
			if(r%2==0) mx[r]=max(mx[r],h),r--;
		}
	}
	int Get(int i){ int ret=0;for(i+=sz;i;i>>=1) ret=max(ret,mx[i]);return ret;}
} Tree;
vector<pair<int,int> > id;
int Find(pair<int,int> x){ return lower_bound(id.begin(),id.end(),x)-id.begin();}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&h[i],&l[i],&r[i]);
		id.pb(mp(l[i],0));id.pb(mp(l[i],1));id.pb(mp(l[i]-1,1));
		id.pb(mp(r[i],0));id.pb(mp(r[i],1));id.pb(mp(r[i]-1,1));
	}
	sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) l[i]=Find(mp(l[i],0)),r[i]=Find(mp(r[i],0));
	Tree.init(id.size());
	for(i=1;i<=n;i++) Tree.Set(l[i],r[i],h[i]);
	int he=0;
	vector<pair<int,int> > sol;
	for(i=0;i+1<id.size();i++)
	{
		int tmp=Tree.Get(i);
		int nxt=Tree.Get(i+1);
		int fi=id[i].first;
		int se=id[i].second;
		if(se==0)
		{
			if(tmp!=he)
			{
				sol.pb(mp(fi,he));
				sol.pb(mp(fi,tmp));
			}
			else if(tmp!=nxt)
			{
                sol.pb(mp(fi,tmp));
                sol.pb(mp(fi,nxt));
			}
		}
		he=tmp;
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}