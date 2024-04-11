#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int inf=1e9+7;
struct SegmentTree
{
	vector<int> mn;
	int sz;
	SegmentTree(){}
	void init(int n){ sz=n;mn.clear();mn.assign(n*2,inf);}
	void Set(int i, int f){ i+=sz-1;mn[i]=f;for(i>>=1;i;i>>=1) mn[i]=min(mn[i<<1],mn[i<<1|1]);}
	int Get(int l, int r)
	{
		int ret=inf;
		for(l+=sz-1,r+=sz-1;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret=min(ret,mn[l]),l++;
			if(r%2==0) ret=min(ret,mn[r]),r--;
		}
		return ret;
	}
} Tree;
const int N=500050;
int a[N],l[N],r[N],ss[N],se[N];
pair<pair<int,int> ,pair<int,int> > ans[N];
int main()
{
	int n,i,j;map<int,int> lst;
	scanf("%i",&n);Tree.init(n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),l[i]=lst[a[i]],lst[a[i]]=i;
	lst.clear();for(i=n;i>=1;i--) r[i]=lst[a[i]],lst[a[i]]=i;
	for(i=1;i<=n;i++)
	{
		if(l[i])
		{
			Tree.Set(l[i],inf);
			ss[i]=l[i];
			se[i]=Tree.Get(l[i]+1,i-1);
			if(se[i]!=inf) ans[i]=mp(mp(ss[i],l[se[i]]),mp(i,se[i]));
		}
		else se[i]=inf,ss[i]=0;
		if(r[i]) Tree.Set(i,r[i]);
	}
	vector<int> sol;
	for(i=1;i<=n;i=j)
	{
		int mn=n+1,taj=0;
		for(j=i;j<mn;j++)
		{
			if(se[j]<mn && ss[j]>=i) mn=se[j],taj=j;
			if(r[r[r[j]]] && r[r[r[j]]]<mn) mn=r[r[r[j]]],taj=j,ans[j]=mp(mp(j,r[j]),mp(r[r[j]],r[r[r[j]]]));
		}
		j++;
		if(taj) sol.pb(taj);
	}
	printf("%i\n",sol.size()*4);
	for(i:sol) printf("%i %i %i %i ",a[ans[i].first.first],a[ans[i].first.second],a[ans[i].second.first],a[ans[i].second.second]);
	return 0;
}