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
const int N=100005;
int sz[N],ans[N];
int fa[N],n,rt;
vector<int> e[N];
map<int,int> mpf,mpo,mpc;
void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		dfs(i),sz[x]+=sz[i];
	mpo[sz[x]]++;
}
void add(map<int,int> &mp,int a,int b){
	if (!(mp[a]+=b)) mp.erase(a);
}
void change(int x,int d,int fa){
	add(mpc,sz[x],d);
	add(mpo,sz[x],-d);
	for (auto i:e[x])
		if (i!=fa) change(i,d,fa);
}
int ask(map<int,int> &mp,int l,int r,int L,int R){
	int ans=n-1;
	for (;l<=r;){
		int mid=(l+r)/2;
		if (L-mid>mid+R) l=mid+1;
		else{
			map<int,int>::iterator it;
			it=mp.lower_bound(L-mid);
			if (it!=mp.end()&&it->fi<=mid+R)
				ans=mid,r=mid-1;
			else l=mid+1;
		}
	}
	return ans; 
}
void solve(int x,int tg){
	add(mpf,sz[x],1);
	add(mpo,sz[x],-1);
	int mx=0,mn=n,id=0,smx=0;
	for (auto i:e[x]){
		if (mx<sz[i]) smx=mx,mx=sz[i],id=i;
		else smx=max(smx,sz[i]);
		mn=min(mn,sz[i]);
	}
	for (auto i:e[x]) if (i!=id) solve(i,0);
	if (id) solve(id,1);
	ans[x]=max(mx,n-sz[x]);
	if (x!=rt) mn=min(mn,n-sz[x]);
	if (n-sz[x]<=mx){
		smx=max(smx,n-sz[x]);
		ans[x]=min(ans[x],ask(mpc,mn,mx,mx,-mn));
	} 
	change(x,1,id);
	add(mpo,sz[x],1);
	if (n-sz[x]>mx){
		smx=mx;
		ans[x]=min(ans[x],ask(mpo,mn,n-sz[x],n-sz[x],-mn));
		ans[x]=min(ans[x],ask(mpf,mn,n-sz[x],n,sz[x]-mn));
	}
	ans[x]=max(ans[x],smx);
	add(mpf,sz[x],-1);
	if (!tg) change(x,-1,0);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		if (!x) rt=y;
		else e[fa[y]=x].PB(y);
	}
	dfs(rt);
	solve(rt,0);
	For(i,1,n) printf("%d\n",ans[i]);
}