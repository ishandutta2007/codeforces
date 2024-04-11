#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
const int H=3*N;
const int M=32*N;
const int inf=1e9+7;
int ls[M],rs[M],mx[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int f)
{
	if(!c) c=++tsz;
	mx[c]=max(mx[c],f);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return mx[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
struct SegmentTreeMin
{
	vector<int> mn;
	int sz;
	SegmentTreeMin(){}
	void init(int n){ sz=n;mn.clear();mn.assign(2*n,inf);}
	void Set(int l, int r, int f)
	{
		for(l+=sz-1,r+=sz-1;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) mn[l]=min(mn[l],f),l++;
			if(r%2==0) mn[r]=min(mn[r],f),r--;
		}
	}
	int Get(int i){ int ret=inf;for(i+=sz-1;i;i>>=1) ret=min(ret,mn[i]);return ret;}
} RT;
int a[N],sol[H];
vector<pair<int,int> > Qs[N];
int main()
{
	int n,i,q,l,r;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	scanf("%i",&q);
	for(i=1;i<=q;i++) scanf("%i %i",&l,&r),Qs[r].pb(mp(l,i));
	RT.init(n);
	for(i=1;i<=n;i++)
	{
		int j,need=inf;
		while(j=Get(root,0,inf,a[i],need))
		{
			RT.Set(1,j,a[j]-a[i]);
			need=a[i]+a[j]>>1;
			need=min(need,a[j]-1);
		}
		need=0;
		while(j=Get(root,0,inf,need,a[i]))
		{
			RT.Set(1,j,a[i]-a[j]);
			need=a[i]+a[j]>>1;
			need=max(need,a[j]+1);
		}
		Set(root,0,inf,a[i],i);
		for(auto p:Qs[i]) sol[p.second]=RT.Get(p.first);
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}