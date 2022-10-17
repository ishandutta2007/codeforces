#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=500005,maxt=maxn<<2;
int n,m,T,ans;
int t[maxn][2],mn[maxt][2];
void update(int l,int r,int now,int p,int v,int tp){
	if(l==r){
		mn[now][tp]+=v;
		return ;
	}
	if(p<=mid)
		update(l,mid,lc(now),p,v,tp);
	else update(mid+1,r,rc(now),p,v,tp);
	mn[now][tp]=min(mn[lc(now)][tp],mn[rc(now)][tp]);
}
int query(int l,int r,int now,int L,int R,int tp){
	if(L<=l&&r<=R)
		return mn[now][tp];
	int res=2;
	if(L<=mid)
		res=min(res,query(l,mid,lc(now),L,R,tp));
	if(mid<R)
		res=min(res,query(mid+1,r,rc(now),L,R,tp));
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int t,x,y,a,b;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			update(1,n,1,x,1,0),update(1,n,1,y,1,1);
		if(t==2)
			update(1,n,1,x,-1,0),update(1,n,1,y,-1,1);
		if(t==3){
			scanf("%d%d",&a,&b);
			if(query(1,n,1,x,a,0)||query(1,n,1,y,b,1))
				puts("Yes");
			else puts("No");
		}
	}
	return 0;
}