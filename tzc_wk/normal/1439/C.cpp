#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define mp make_pair
#define pb push_back
#define ppb pop_back
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
const int MAXN=2e5;
int n,m,a[MAXN+5];
struct node{int l,r,tag,mn;ll sum;} s[MAXN*4+5];
void pushup(int k){
	s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].sum=s[k].mn=a[l],void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void pushdown(int k){
	if(s[k].tag){
		s[k<<1].sum=1ll*s[k].tag*(s[k<<1].r-s[k<<1].l+1);
		s[k<<1|1].sum=1ll*s[k].tag*(s[k<<1|1].r-s[k<<1|1].l+1);
		s[k<<1].tag=s[k<<1|1].tag=s[k<<1].mn=s[k<<1|1].mn=s[k].tag;
		s[k].tag=0;
	}
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r) return s[k].sum=1ll*x*(r-l+1),s[k].tag=s[k].mn=x,void();
	int mid=(pushdown(k),s[k].l+s[k].r>>1);
	if(r<=mid) modify(k<<1,l,r,x);else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);pushup(k);
}
ll query(int k,int l,int r){
	if(l>r) return 0;
	if(l<=s[k].l&&s[k].r<=r) return s[k].sum;
	int mid=(pushdown(k),s[k].l+s[k].r>>1);
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int getfst(int x){//the leftmost position <= x
	int l=1,r=n,p=n+1;
	while(l<=r){
		int mid=l+r>>1;
		if(query(1,mid,mid)<=x) p=mid,r=mid-1;
		else l=mid+1;
	} return p;
}
void walk(int k,ll &sum,int &ans){
	if(s[k].mn>sum) return;
	if(s[k].sum<=sum) return sum-=s[k].sum,ans+=s[k].r-s[k].l+1,void();
	pushdown(k);walk(k<<1,sum,ans);walk(k<<1|1,sum,ans);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while(m--){
		int opt,x,y;scanf("%d%d%d",&opt,&x,&y);
		if(opt==1){
			int ps=getfst(y);
			if(ps<=x) modify(1,ps,x,y);
		} else {
			int ans=0;ll ny=y+query(1,1,x-1);
			walk(1,ny,ans);printf("%d\n",ans-(x-1));
		}
	}
	return 0;
}