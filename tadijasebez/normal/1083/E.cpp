#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000050;
const ll inf=9e18;
const int lim=1e9+7;
struct Line
{
	ll k,n;
	Line(ll a=0, ll b=0):k(a),n(b){}
	ll Get(ll x){ return k*x+n;}
};
int ls[N],rs[N],tsz,root;
Line line[N];
void AddLine(int &c, int ss, int se, Line k)
{
	if(!c){ c=++tsz;line[c]=k;return;}
	ll A=line[c].Get(ss),B=k.Get(ss),C=line[c].Get(se),D=k.Get(se);
	if(A>=B && C>=D) return;
	if(A<=B && C<=D){ line[c]=k;return;}
	int mid=ss+se>>1;
	if(A<B) swap(line[c],k);
	if(line[c].Get(mid)>=k.Get(mid)) AddLine(rs[c],mid+1,se,k);
	else swap(line[c],k),AddLine(ls[c],ss,mid,k);
}
ll Get(int c, int ss, int se, int qi)
{
	if(!c) return -inf;
	ll ans=line[c].Get(qi);
	if(ss==se) return ans;
	int mid=ss+se>>1;
	if(qi<=mid) ans=max(ans,Get(ls[c],ss,mid,qi));
	else ans=max(ans,Get(rs[c],mid+1,se,qi));
	return ans;
}
int x[N],y[N],id[N];
ll dp[N],a[N];
bool comp(int i, int j){ return x[i]>x[j];}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i %lld",&x[i],&y[i],&a[i]),id[i]=i;
    sort(id+1,id+1+n,comp);
    AddLine(root,1,lim,Line(0,0));
    ll ans=0;
    for(int j=1;j<=n;j++)
	{
		i=id[j];
		dp[i]=Get(root,1,lim,x[i])-a[i]+(ll)x[i]*y[i];
		AddLine(root,1,lim,Line(-y[i],dp[i]));
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}