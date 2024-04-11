#include<bits/stdc++.h>
using namespace std;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define pi pair<int ,int >
#define mcp(x,y) make_pair(x,y)
#define fi first
#define se second

const int N = 2e6+9;
int n,m;
struct pp{int x,l,r;}a[N];
int p[N],cnt;
void LSH(){
	sort(p+1,p+cnt+1);
	cnt=unique(p+1,p+cnt+1)-p-1;
	for(int i=1;i<=m;i++){
		a[i].l=lower_bound(p+1,p+cnt+1,a[i].l)-p;
		a[i].r=lower_bound(p+1,p+cnt+1,a[i].r)-p;
	}
    cnt+=100;
	return ;
}
struct seg{pi mx,tag;}t[N<<2];
void pushup(int c){
	t[c].mx=max(t[ls(c)].mx,t[rs(c)].mx);
	return ;
}
void upd(int c,pi x){t[c].mx=max(t[c].mx,x),t[c].tag=max(t[c].tag,x);return ;}
void pushdown(int c){
	if(t[c].tag.fi){
		upd(ls(c),t[c].tag);
		upd(rs(c),t[c].tag);
		t[c].tag=mcp(0,0);
	}
	return ;
}
void build(int c,int l,int r){
	t[c].mx=t[c].tag=mcp(0,0);
	if(l==r) return ;
	int mid=(l+r)>>1;build(ls(c),l,mid);build(rs(c),mid+1,r);
	pushup(c);return ;
}

void modi(int c,int l,int r,int x,int y,int z,int id){
	if(x<=l&&r<=y){
		upd(c,mcp(z,id));
		return ;
	}
	pushdown(c);int mid=(l+r)>>1;
	if(x<=mid) modi(ls(c),l,mid,x,y,z,id);
	if(y>mid) modi(rs(c),mid+1,r,x,y,z,id);
	pushup(c);return ;
}

pi query(int c,int l,int r,int x,int y){
	if(x<=l&&r<=y) return t[c].mx;
	pushdown(c);int mid=(l+r)>>1;pi ans=mcp(0,0);
	if(x<=mid){
        ans=max(ans,query(ls(c),l,mid,x,y));
	}
	if(y>mid){
        ans=max(ans,query(rs(c),mid+1,r,x,y));
	}
	pushup(c);return ans;
}

vector<int >v[N];
int pre[N],oo[N];

int main(){
	scanf("%d%d",&n,&m);cnt=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].l,&a[i].r);
		p[++cnt]=a[i].l,p[++cnt]=a[i].r;
	}
	LSH();
	
	build(1,1,cnt);
    for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<=m;i++) v[a[i].x].push_back(i);
	for(int i=1;i<=n;i++){
		pi ans=mcp(0,0);
		for(int j=0;j<v[i].size();j++){
			ans=max(ans,query(1,1,cnt,a[v[i][j]].l,a[v[i][j]].r));
		}
		pre[i]=ans.se;
		int k=ans.fi+1;
		for(int j=0;j<v[i].size();j++)
			modi(1,1,cnt,a[v[i][j]].l,a[v[i][j]].r,k,i);
	}
	printf("%d\n",n-query(1,1,cnt,1,cnt).fi);
	if(n-query(1,1,cnt,1,cnt).fi>0){
		int k=query(1,1,cnt,1,cnt).se;
		while(k){
			oo[k]=1;
			k=pre[k];
		}
		for(int i=1;i<=n;i++)
			if(!oo[i]) printf("%d ",i);
		puts("");	
	}
	return 0;
}