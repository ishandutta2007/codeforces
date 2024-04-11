#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
	friend bool operator <(edge a,edge b){
		return a.w<b.w;
	}
} e[200005];
vector<edge> g[200005];
int n,m;
struct query{
	int id,x;
	friend bool operator <(query a,query b){
		return a.x<b.x;
	}
} q[200005];
struct SegTree{
	struct node{
		int l,r,val;
	} s[800005];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	inline void modify(int k,int ind,int x){
		if(s[k].l==s[k].r){
			s[k].val=x*(x-1)/2;
			return;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(ind<=mid)	modify(k<<1,ind,x);
		else			modify(k<<1|1,ind,x);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
	}
} st;
int fa[200005],size[200005],ans[200005];
inline void init(){
	for(int i=1;i<=n;i++)	fa[i]=i,size[i]=1;
	st.build(1,1,n);
}
inline int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
inline void merge(int a,int b){
//	cout<<"merge: "<<a<<" "<<b<<endl;
	int x=find(a),y=find(b);
	if(x==y)	return;
	fa[x]=y;
	size[y]+=size[x];
	size[x]=0;
	st.modify(1,x,0);
	st.modify(1,y,size[y]);
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=m;i++)	cin>>q[i].x,q[i].id=i;
	init();
	sort(e+1,e+n);
	sort(q+1,q+1+m);
	int cur=1;
	for(int i=1;i<=m;i++){
		while(e[cur].w<=q[i].x&&cur<n){
			merge(e[cur].u,e[cur].v);
			cur++;
		}
//		cout<<st.s[i].val<<endl;
		ans[q[i].id]=st.s[1].val;
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<" ";
	return 0;
}