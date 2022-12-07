#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=300005;
map<int,int> mp[N];
int fa[N*2],sz1[N*2],sz2[N*2];
int px[N*2],py[N*2],top,n;
ll ans,dif[N*2];
vector<pii> t[N*4];
int get(int x){
	return x==fa[x]?x:get(fa[x]);
}
void insert(int k,int l,int r,int x,int y,pii v){
	if (l==x&&r==y){
		t[k].PB(v);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) insert(k*2,l,mid,x,y,v);
	else if (x>mid) insert(k*2+1,mid+1,r,x,y,v);
	else{
		insert(k*2,l,mid,x,mid,v);
		insert(k*2+1,mid+1,r,mid+1,y,v);
	}
}
void solve(int k,int l,int r){
	int tmp=top;
	For(i,0,t[k].size()-1){
		int x=get(t[k][i].fi);
		int y=get(t[k][i].se);
		if (x==y) continue;
		//printf("%d %d %d %d\n",l,r,x,y);
		dif[++top]=ans;
		ans-=1ll*sz1[x]*sz2[x];
		ans-=1ll*sz1[y]*sz2[y];
		if (sz1[x]+sz2[x]<sz1[y]+sz2[y]) swap(x,y);
		px[top]=x; py[top]=y; fa[y]=x;
		sz1[x]+=sz1[y]; sz2[x]+=sz2[y];
		ans+=1ll*sz1[x]*sz2[x];
	}
	if (l==r)
		printf("%lld ",ans);
	else{
		int mid=(l+r)/2;
		solve(k*2,l,mid);
		solve(k*2+1,mid+1,r);
	}
	for (;top!=tmp;top--){
		ans=dif[top];
		int x=px[top],y=py[top];
		fa[y]=y;
		sz1[x]-=sz1[y];
		sz2[x]-=sz2[y];
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		if (mp[x][y]==0) mp[x][y]=i;
		else{
			insert(1,1,n,mp[x][y],i-1,pii(x,y+N));
			mp[x][y]=0;
		}
	}
	For(i,1,n)
		for (auto j:mp[i])
			if (j.se!=0)
				insert(1,1,n,j.se,n,pii(i,j.fi+N));
	For(i,1,2*N-1) fa[i]=i;
	For(i,1,N-1) sz1[i]=sz2[i+N]=1;
	solve(1,1,n);
}