#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=200050;
const int inf=1e9+7;
struct SegmentTree
{
	vector<int> mx;
	int sz;
	void init(int n){ mx.assign(n*2,-inf);sz=n;}
	SegmentTree(){}
	void Set(int i, int f){ for(i+=sz-1;i;i>>=1) mx[i]=max(mx[i],f);}
	int Get(int l, int r)
	{
		int ans=-inf;
		for(l+=sz-1,r+=sz-1;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans=max(ans,mx[l++]);
			if(r%2==0) ans=max(ans,mx[r--]);
		}
		return ans;
	}
} ST;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<pair<int,int> > work;
	ST.init(n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),ST.Set(i,a[i]),work.pb(mp(a[i],i));
	sort(work.begin(),work.end());
	int mx=work.back().first;
	for(i=0;i<work.size() && work[i].first<mx;i+=2)
	{
		if(i+1==work.size() || work[i+1].first!=work[i].first) return 0*printf("NO\n");
		int l=work[i].second;
		int r=work[i+1].second;
		if(ST.Get(l,r)>work[i].first) return 0*printf("NO\n");
	}
	printf("YES\n");
	return 0;
}