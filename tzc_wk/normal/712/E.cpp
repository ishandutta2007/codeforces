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
struct node{
	int l,r;double v,w;
} s[100005<<2];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int x,double v){
	if(s[k].l==s[k].r){s[k].v=s[k].w=(1-v)/v;return;}
	int mid=(s[k].l+s[k].r)>>1;
	if(x<=mid) modify(k<<1,x,v);
	else modify(k<<1|1,x,v);
	s[k].v=s[k<<1].v*s[k<<1|1].v;
	s[k].w=s[k<<1].w+s[k<<1].v*s[k<<1|1].w;
}
double query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)*query(k<<1|1,mid+1,r);
}
double queryw(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].w;
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return queryw(k<<1,l,r);
	else if(l>mid) return queryw(k<<1|1,l,r);
	else return queryw(k<<1,l,mid)+query(k<<1,l,mid)*queryw(k<<1|1,mid+1,r);
}
int n,q;
int main(){
	scanf("%d%d",&n,&q);build(1,1,n);
	for(int i=1;i<=n;i++){
		int a,b;scanf("%d%d",&a,&b);modify(1,i,1.0*a/b);
	}
	for(int i=1;i<=q;i++){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x,a,b;scanf("%d%d%d",&x,&a,&b);
			modify(1,x,1.0*a/b);
		} else {
			int l,r;scanf("%d%d",&l,&r);
			double mul=queryw(1,l,r);
			printf("%.16lf\n",1.0/(1.0+mul));
		}
	}
	return 0;
}