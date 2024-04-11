/*
Contest: -
Problem: Codeforces 319E
Author: tzc_wk
Time: 2020.10.13
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
int n,m,id[100005];
struct query{
	int opt,l,r;
} q[100005];
int key[200005],cnt=0,hs[200005],num=0;
int L[200005],R[200005];
struct node{
	int l,r;
	vector<int> v;
} s[200005<<2];
inline void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
int f[200005];
inline int find(int x){return (f[x]==x)?x:(f[x]=find(f[x]));}
inline void modify(int k,int x,int y){
	if(s[k].v.size()){
		for(int i=0;i<s[k].v.size();i++){
			int z=s[k].v[i];z=find(z);f[z]=y;
			L[y]=min(L[y],L[z]);R[y]=max(R[y],R[z]);
		}
		s[k].v.clear();s[k].v.pb(y);
	}
	if(s[k].l==s[k].r) return;
	int mid=(s[k].l+s[k].r)>>1;
	if(x<=mid) modify(k<<1,x,y);
	else modify(k<<1|1,x,y);
}
inline void add(int k,int l,int r,int x){
	if(l==s[k].l&&s[k].r==r){
		s[k].v.pb(x);return;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) add(k<<1,l,r,x);
	else if(l>mid) add(k<<1|1,l,r,x);
	else add(k<<1,l,mid,x),add(k<<1|1,mid+1,r,x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&q[i].opt,&q[i].l,&q[i].r);
		if(q[i].opt==1) key[++cnt]=q[i].l,key[++cnt]=q[i].r;
	}
	sort(key+1,key+cnt+1);key[0]=-0x3f3f3f3f;
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	build(1,1,num);
	for(int i=1;i<=n;i++) if(q[i].opt==1){
		q[i].l=lower_bound(hs+1,hs+num+1,q[i].l)-hs;
		q[i].r=lower_bound(hs+1,hs+num+1,q[i].r)-hs;
		m++;L[m]=q[i].l;R[m]=q[i].r;id[i]=m;
	}
	for(int i=1;i<=m;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		if(q[i].opt==1){
			modify(1,q[i].l,id[i]);modify(1,q[i].r,id[i]);
			if(q[i].l+1<=q[i].r-1) add(1,q[i].l+1,q[i].r-1,id[i]);
		}
		else{
			int x=find(q[i].l),y=find(q[i].r);
			if((x==y)||(L[y]<L[x]&&L[x]<R[y])||(L[y]<R[x]&&R[x]<R[y])) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}