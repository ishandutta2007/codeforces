#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10,inf=1073741823;
struct node{
	int r1,c1,r2,c2,num,ans;
	bool operator<(const node b)const{
		return r2<b.r2;
	}
}q[N];
struct seg{
	int t[N<<2];
	void pushup(int rt){
		t[rt]=min(t[rt<<1],t[rt<<1|1]);
	}
	void build(int rt,int l,int r){
		if(l==r)return t[rt]=inf,void();
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	void modify(int rt,int l,int r,int X,int d){
		if(l==r)return t[rt]=d,void();
		int mid=(l+r)>>1;
		if(X<=mid)modify(rt<<1,l,mid,X,d);
		else modify(rt<<1|1,mid+1,r,X,d);
		pushup(rt);
	}
	int query(int rt,int l,int r,int L,int R){
		if(L>R)return 1e9+7;
		if(L<=l&&r<=R)return t[rt];
		int mid=(l+r)>>1,res=1e9+7;
		if(L<=mid)res=min(res,query(rt<<1,l,mid,L,R));
		if(R>mid)res=min(res,query(rt<<1|1,mid+1,r,L,R));
		return res;
	}
}tr1,tr2;
int a[N],st[N][21],cl[N],stk[N],tp;
int query(int l,int r){
	if(l>r)swap(l,r);
	int w=cl[r-l+1];
	return min(st[l][w],st[r-(1<<w)+1][w]);
}
int findpos(int l,int r,int d){
	int res=l-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[stk[mid]]<=d)res=mid,l=mid+1;
		else r=mid-1;
	}
	return res+1;
}
void calc(node &q,int val){
	int ans=abs(min(q.c1,val)-q.c2);
	int pos1=lower_bound(stk+1,stk+tp+1,q.r1)-stk;
	int pos2=findpos(pos1,tp,q.c2);
	if(pos2-1<=tp&&stk[pos2-1]>=q.r1)ans=min(ans,abs(a[stk[pos2-1]]-q.c2)+1);
	if(pos2-0<=tp&&stk[pos2-0]>=q.r1)ans=min(ans,abs(a[stk[pos2-0]]-q.c2)+1);
	q.ans=min(q.ans,abs(q.r1-q.r2)+ans);
}
void comp(node &q,int n){
	int val=min(query(q.r1,q.r2),q.c1);
	if(q.r1<=q.r2)calc(q,val);
	int ed=lower_bound(stk+1,stk+tp+1,q.r1+1)-stk-1;
	val=min(val,q.c1);
	int pos1=findpos(1,ed,val),pos2=findpos(1,ed,q.c2);
	if(val>=q.c2)
	{
		int val1=tr1.query(1,1,n,pos2,pos1-1)-q.c2+q.r1+q.r2;
		int val2=tr2.query(1,1,n,1,pos2-1)+q.c2+q.r1+q.r2;
		q.ans=min(q.ans,min(val1,val2));
	}
	else 
	{
		int val1=tr1.query(1,1,n,pos2,ed)-q.c2+q.r1+q.r2+1;
		int val2=tr2.query(1,1,n,pos1,pos2-1)+q.c2+q.r1+q.r2+1;
		q.ans=min(q.ans,min(val1,val2));
	}
}
void solve(int n,int m){
	for(int i=1;i<=n;++i)st[i][0]=a[i];
	for(int w=1;w<19;++w){for(int i=1;i+(1<<w)-1<=n;++i)
		st[i][w]=min(st[i][w-1],st[i+(1<<(w-1))][w-1]);
	}
	for(int i=1;i<=m;++i){
		int val=min(query(q[i].r1,q[i].r2),q[i].c1);
		q[i].ans=min(q[i].ans,abs(q[i].r1-q[i].r2)+abs(val-q[i].c2));
	}
	stable_sort(q+1,q+m+1);
	tr1.build(1,1,n),tr2.build(1,1,n),tp=0;int pos=1;
	for(int i=1;i<=n;++i){
		while(tp&&a[stk[tp]]>=a[i])--tp;
		stk[++tp]=i;
		tr1.modify(1,1,n,tp,-2*i+a[i]);
		tr2.modify(1,1,n,tp,-2*i-a[i]);
		while(pos<=m&&q[pos].r2==i)comp(q[pos++],n);
	}
}
int ans[N];
int main(){
	int n;
	scanf("%d",&n);
	cl[0]=-1;
	for(int i=1;i<=n;++i)cl[i]=cl[i>>1]+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%d",&q[i].r1,&q[i].c1,&q[i].r2,&q[i].c2);
		q[i].num=i,q[i].ans=abs(q[i].r1-q[i].r2)+q[i].c2+1;
	}
	solve(n,m);
	reverse(a+1,a+n+1);
	for(int i=1;i<=m;++i){
		q[i].r1=n-q[i].r1+1;
		q[i].r2=n-q[i].r2+1;
	}
	solve(n,m);
	for(int i=1;i<=m;i++){
		ans[q[i].num]=q[i].ans;
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}