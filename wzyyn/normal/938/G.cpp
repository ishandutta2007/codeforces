#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
struct node{
	int x,y,v,st,ed;
}q[N*2];
int n,m,Q,top,pos;
int fa[N],sz[N];
int v[N],dif[N];
int qx[N],qy[N],tp[N];
map<int,int> mp[N];
vector<int> vec[N*4];
pii qq[N];
struct Bas{
	int a[32];
	void insert(int x){
		Rep(i,29,0)
			if (x&(1<<i))
				if (!a[i]){
					a[i]=x;
					return;
				}
				else x^=a[i];
	}
}B[32];
int get(int x){
	v[x]=0;
	if (x==fa[x]) return x;
	int ans=get(fa[x]);
	v[x]=v[fa[x]]^dif[x];
	return ans;	
}
void insert(int k,int l,int r,int id){
	if (q[id].st<=l&&r<=q[id].ed)
		return vec[k].PB(id),void(0);
	int mid=(l+r)/2;
	if (q[id].st<=mid) insert(k*2,l,mid,id);
	if (q[id].ed>mid) insert(k*2+1,mid+1,r,id);
}

void merge(int id,int p){
	int x=get(q[id].x);
	int y=get(q[id].y);
	if (x==y)
		B[p].insert(v[q[id].x]^v[q[id].y]^q[id].v);
	else{
		if (sz[x]<sz[y]) swap(x,y);
		fa[y]=x;
		sz[x]+=sz[y];
		dif[y]=v[q[id].x]^v[q[id].y]^q[id].v;
		qq[++pos]=pii(x,y);
	}
}
void release(){
	int x=qq[pos].fi;
	int y=qq[pos].se;
	fa[y]=y; sz[x]-=sz[y];
	--pos;
}
void solve(int k,int l,int r,int d){
	//cout<<k<<' '<<l<<' '<<r<<' '<<d<<endl; 
	int tmp=pos; 
	B[d]=B[d-1];
	for (auto i:vec[k]) merge(i,d);
	if (l==r){
		if (tp[l]==3){
			get(qx[l]); get(qy[l]);
			int ans=v[qx[l]]^v[qy[l]];
			Rep(i,29,0)
				if (B[d].a[i]&&(ans&(1<<i)))
					ans^=B[d].a[i];
			printf("%d\n",ans);
		}
	}
	else{
		int mid=(l+r)/2;
		solve(k*2,l,mid,d+1);
		solve(k*2+1,mid+1,r,d+1);
	}
	for (;pos>tmp;release());
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) fa[i]=i,sz[i]=1;
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		mp[x][y]=mp[y][x]=++top;
		q[top]=(node){x,y,v,1,0};
	}
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%d",&tp[i]);
		if (tp[i]==1){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			mp[x][y]=mp[y][x]=++top;
			q[top]=(node){x,y,v,i,0};
		}
		if (tp[i]==2){
			int x,y;
			scanf("%d%d",&x,&y);
			q[mp[x][y]].ed=i;
			mp[x][y]=mp[y][x]=-1;
		}
		if (tp[i]==3)
			scanf("%d%d",&qx[i],&qy[i]);
	}
	For(i,1,n)
		for (auto j:mp[i])
			if (j.se!=-1)
				q[j.se].ed=Q;
	For(i,1,top){
		//printf("%d %d %d %d %d\n",q[i].x,q[i].y,q[i].v,q[i].st,q[i].ed);
		insert(1,1,Q,i);
	}
	solve(1,1,Q,1);
}