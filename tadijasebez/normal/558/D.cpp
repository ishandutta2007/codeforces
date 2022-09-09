#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
vector<ll> idx;
int Find(ll x){ return lower_bound(idx.begin(),idx.end(),x)-idx.begin()+1;}
const int N=100050;
const int M=12*N;
int cnt[M],id[M],Max[M],lzy[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qs, int qe, int f)
{
	if(!c) c=++tsz,cnt[c]=se-ss+1,id[c]=ss;
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se){ lzy[c]+=f;Max[c]+=f;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,f);
	Set(rs[c],mid+1,se,qs,qe,f);
	if(Max[ls[c]]>Max[rs[c]]) Max[c]=Max[ls[c]]+lzy[c],cnt[c]=cnt[ls[c]],id[c]=id[ls[c]];
	if(Max[rs[c]]>Max[ls[c]]) Max[c]=Max[rs[c]]+lzy[c],cnt[c]=cnt[rs[c]],id[c]=id[rs[c]];
	if(Max[ls[c]]==Max[rs[c]]) Max[c]=Max[ls[c]]+lzy[c],cnt[c]=cnt[ls[c]]+cnt[rs[c]],id[c]=id[ls[c]];
}
int A[N],D[N];
ll B[N],C[N];
int main()
{
	int h,q,i,lvl,t;
	ll l,r;
	scanf("%i %i",&h,&q);
	if(q==0 && h==1) return printf("1\n"),0;
	ll n=((ll)1)<<h;n--;
	ll b=((ll)1)<<(h-1);
	idx.pb(n);idx.pb(b);
	if(n-1>=b) idx.pb(n-1);
	if(b+1<=n) idx.pb(b+1);
	int m=q;
	for(i=1;i<=q;i++)
	{
		scanf("%i %lld %lld %i",&A[i],&B[i],&C[i],&D[i]);
		lvl=h-A[i];
		l=B[i];
		r=C[i];
		l<<=lvl;
		r<<=lvl;
		r+=(((ll)1)<<lvl)-1;
		idx.pb(l);
		if(l+1<=n) idx.pb(l+1);
		if(l-1>=b) idx.pb(l-1);
		idx.pb(r);
		if(r-1>=b) idx.pb(r-1);
		if(r+1<=n) idx.pb(r+1);
	}
	sort(idx.begin(),idx.end());
	idx.erase(unique(idx.begin(),idx.end()),idx.end());
	for(i=1;i<idx.size();i++) if(idx[i]==idx[i-1]) printf("???\n");
	int sz=idx.size();
	for(i=1;i<=q;i++)
	{
		lvl=h-A[i];
		l=B[i];
		r=C[i];
		l<<=lvl;
		r<<=lvl;
		r+=(((ll)1)<<lvl)-1;
		t=D[i];
		if(t) Set(root,1,sz,Find(l),Find(r),1);
		else Set(root,1,sz,Find(l),Find(r),-1),Set(root,1,sz,1,sz,1);
	}
	if(Max[root]!=m) printf("Game cheated!\n");
	else if(cnt[root]==1) printf("%lld\n",idx[id[root]-1]);
	else printf("Data not sufficient!\n");
	return 0;
}