#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
int n;
struct seg{
	int l,r,t;
} a[200005];
vector<int> vr[400005];
int key[400005],hs[400005],cnt=0,num=0;
int dp[400005];
struct segtree{
	struct node{
		int l,r,val,lz;
	} s[400005<<2];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return;
		int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void pushdown(int k){
		if(s[k].lz){
			s[k<<1].lz+=s[k].lz;s[k<<1].val+=s[k].lz;
			s[k<<1|1].lz+=s[k].lz;s[k<<1|1].val+=s[k].lz;
			s[k].lz=0;
		}
	}
	void modify(int k,int l,int r,int v){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val+=v;s[k].lz+=v;return;
		} pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid) modify(k<<1,l,r,v);
		else if(l>mid) modify(k<<1|1,l,r,v);
		else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
		s[k].val=max(s[k<<1].val,s[k<<1|1].val);
	}
} b,w;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].t);
		key[++cnt]=a[i].l;key[++cnt]=a[i].r;
	}
	sort(key+1,key+cnt+1);
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	b.build(1,0,num);w.build(1,0,num);
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(hs+1,hs+num+1,a[i].l)-hs;
		a[i].r=lower_bound(hs+1,hs+num+1,a[i].r)-hs;
		vr[a[i].r].push_back(i);
	}
	for(int i=1;i<=num;i++){
		for(int j=0;j<vr[i].size();j++){
			int id=vr[i][j];
			if(a[id].t==2) b.modify(1,0,a[id].l-1,1);
			else w.modify(1,0,a[id].l-1,1);
		}
		dp[i]=max(b.s[1].val,w.s[1].val);
		b.modify(1,i,i,dp[i]);w.modify(1,i,i,dp[i]);
	}
	printf("%d\n",dp[num]);
	return 0;
}