#include <bits/stdc++.h>
using namespace std;
#define ldb long double
#define pb push_back
const int N=100050;
const int M=4*N;
int l[N],r[N],h[N],a[N],b[N],z[N];
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
struct BIT
{
	ldb val[M];
	BIT(){ for(int i=0;i<M;i++) val[i]=1;}
	void Set(int i, ldb f){ for(;i<M;i+=i&-i) val[i]*=f;}
	void Set(int l, int r, ldb f){ Set(l,f);Set(r+1,(ldb)1/f);}
	ldb Get(int i){ ldb ret=1;for(;i;i-=i&-i) ret*=val[i];return ret;}
};
struct SegmentTree
{
	ldb val[1<<20];
	SegmentTree(){ for(int i=0;i<(1<<20);i++) val[i]=1;}
	void Set(int l, int r, ldb f)
	{
		for(l+=1<<19,r+=1<<19;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) val[l++]*=f;
			if(r%2==0) val[r--]*=f;
		}
	}
	ldb Get(int x){ ldb ret=1;for(x+=1<<19;x;x>>=1) ret*=val[x];return ret;}
} Tree;
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i %i %i %i",&a[i],&h[i],&l[i],&r[i]),id.pb(a[i]),id.pb(a[i]-h[i]),id.pb(a[i]+h[i]);
	for(i=1;i<=m;i++) scanf("%i %i",&b[i],&z[i]),id.pb(b[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++)
	{
		Tree.Set(Find(a[i]-h[i]),Find(a[i])-1,(ldb)(100-l[i])/100);
		Tree.Set(Find(a[i])+1,Find(a[i]+h[i]),(ldb)(100-r[i])/100);
	}
	ldb sol=0;
	for(i=1;i<=m;i++) sol+=Tree.Get(Find(b[i]))*z[i];
	cout << fixed << setprecision(12) << sol << "\n";
	//printf("%.12llf\n",sol);
	return 0;
}