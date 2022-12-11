// LUOGU_RID: 90651429
#include <bits/stdc++.h>
using namespace std;
constexpr int max_n=100000,max_q=1000000,max_node=max_n*100,max_v=1000000000;
struct node{
	int mx,lsn,rsn;
};
node tr[max_node+1];
int tr_cnt;
int a[max_n+1],rt[max_n+1],c[max_n+1];
vector<pair<int,int> > que[max_n+1];
int ans[max_q+1];
void update(int&rt,const int l,const int r,const int pos,const int val){
	tr[++tr_cnt]=tr[rt];
	rt=tr_cnt;
	tr[rt].mx=val;
	if(l==r)
		return;
	const int mid=(l+r)>>1;
	if(pos<=mid)
		update(tr[rt].lsn,l,mid,pos,val);
	else
		update(tr[rt].rsn,mid+1,r,pos,val);
}
int query(const int rt,const int l,const int r,const int lft,const int rgt){
	if(!rt)
		return 0;
	if(lft<=l&&r<=rgt)
		return tr[rt].mx;
	const int mid=(l+r)>>1;
	if(lft<=mid)
		if(rgt>mid)
			return max(query(tr[rt].lsn,l,mid,lft,rgt),query(tr[rt].rsn,mid+1,r,lft,rgt));
		else
			return query(tr[rt].lsn,l,mid,lft,rgt);
	else
		return query(tr[rt].rsn,mid+1,r,lft,rgt);
}
void update(int p,const int v){
//	fprintf(stderr,"update %d %d\n",p,v);
	for(v<c[p]&&(c[p]=v); (p&=p-1); v<c[p]&&(c[p]=v));
}
int query(int p,const int n){
//	fprintf(stderr,"query %d:",p);
	int ans=c[p];
	for(; (p+=p&(-p))<=n; c[p]<ans&&(ans=c[p]));
//	fprintf(stderr," %d\n",ans);
	return ans;
}
int main(){
	int n,m;
	scanf("%d",&n);
	memset(c,63,sizeof(c));
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1,l,r; i<=m; ++i){
		scanf("%d%d",&l,&r);
		que[r].emplace_back(l,i);
	}
	for(int i=1; i<=n; ++i){
		rt[i]=rt[i-1];
		for(int l=0,r=a[i],u=i,t; l<=r&&(t=query(rt[u],0,max_v,l,r)); u=t-1,l=((a[i]+a[t])>>1)+1)
			update(t,a[i]-a[t]);
		for(int l=a[i],r=max_v,u=i,t; l<=r&&(t=query(rt[u],0,max_v,l,r)); u=t-1,r=(a[i]+a[t]-1)>>1)
			update(t,a[t]-a[i]);
		for(const pair<int,int>&x:que[i])
			ans[x.second]=query(x.first,n);
		update(rt[i],0,max_v,a[i],i);
	}
	for(int i=1; i<=m; ++i)
		printf("%d\n",ans[i]);
	return 0;
}