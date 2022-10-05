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
const int MAXN=5e5+5;
int n,x[MAXN],y[MAXN],c[MAXN],key[MAXN<<1],hs[MAXN<<1],num=0;
vector<int> t[MAXN<<1];
struct node{
	int l,r;ll v,lz,wh;
} s[MAXN<<3];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].wh=l;if(l==r){return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void pushdown(int k){
	if(s[k].lz){
		s[k<<1].v+=s[k].lz;s[k<<1].lz+=s[k].lz;
		s[k<<1|1].v+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){s[k].v+=x;s[k].lz+=x;return;}
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	s[k].v=s[k<<1].v;s[k].wh=s[k<<1].wh;
	if(s[k<<1|1].v>s[k].v) s[k].v=s[k<<1|1].v,s[k].wh=s[k<<1|1].wh;
}
ll query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return max(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
ll querywh(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].wh;
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return querywh(k<<1,l,r);
	else if(l>mid) return querywh(k<<1|1,l,r);
	else{
		int v1=query(k<<1,l,mid),v2=query(k<<1|1,mid+1,r);
		if(v1>v2) return querywh(k<<1,l,mid);
		else return querywh(k<<1|1,mid+1,r);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
		if(x[i]<y[i]) swap(x[i],y[i]);
		key[i*2-1]=x[i];key[i*2]=y[i];
	} sort(key+1,key+(n<<1)+1);key[0]=-1;
	for(int i=1;i<=(n<<1);i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	build(1,1,num);
	for(int i=1;i<=num;i++) modify(1,i,i,-hs[i]+hs[1]);
	for(int i=1;i<=n;i++){
		x[i]=lower_bound(hs+1,hs+num+1,x[i])-hs;
		y[i]=lower_bound(hs+1,hs+num+1,y[i])-hs;
		modify(1,x[i],num,c[i]);t[y[i]].pb(i);
	}
	ll ans=0;int x1=1145141919,y1=1145141919,x2=1145141919,y2=1145141919;
	for(int i=1;i<=num;i++){
		ll v=query(1,i,num);
//		printf("%d %lld\n",i,v);
		int wh=querywh(1,i,num);
		if(v>ans) ans=v,x1=y1=hs[i],x2=y2=hs[wh];
		for(int id:t[i]) modify(1,x[id],num,-c[id]);
		if(i!=num) modify(1,i+1,num,hs[i+1]-hs[i]);
	}
	printf("%lld\n%d %d %d %d\n",ans,x1,y1,x2,y2);
	return 0;
}