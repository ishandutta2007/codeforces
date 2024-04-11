#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

struct mm{
	int max,min;
}tree[16][N*3];
int n,k,q,a[N][6];

void update(int i,int l,int r,int x,int ind,int itree){
	if(l==r){
		tree[itree][i].max = tree[itree][i].min = x;
		return;
	}
	int mid = (l+r>>1);
	if(ind<=mid) update(i<<1,l,mid,x,ind,itree);
	else update((i<<1)+1,mid+1,r,x,ind,itree);
	tree[itree][i].max = max(tree[itree][i<<1].max, tree[itree][(i<<1)+1].max);
	tree[itree][i].min = min(tree[itree][i<<1].min, tree[itree][(i<<1)+1].min);
}

mm query(int i,int l,int r,int ql,int qr,int itree){
	if(l==ql&&r==qr)return {tree[itree][i].max,tree[itree][i].min};
	int mid = (l+r>>1);
	if(qr<=mid)return query(i<<1,l,mid,ql,qr,itree);
	else if(ql>mid) return query((i<<1)+1,mid+1,r,ql,qr,itree);
	else{
		mm lans,rans;
		lans = query(i<<1,l,mid,ql,mid,itree);
		rans = query((i<<1)+1,mid+1,r,mid+1,qr,itree);
		return {max(lans.max,rans.max),min(lans.min,rans.min)};
	}
}

void updateall(int i){
	rep(id,0,(1<<k-1)-1){
		int sum = a[i][1];
		rep(j,2,k)sum += (((id>>j-2&1)<<1)-1)*a[i][j];
		update(1,1,n,sum,i,id);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&k);
	rep(i,1,n)rep(j,1,k)scanf("%d",&a[i][j]);
	rep(i,1,n*2)rep(j,0,15)tree[j][i].min=1e9,tree[j][i].max=-1e9;
	rep(i,1,n)updateall(i);
	
	scanf("%d",&q);
	while(q--){
		int l,r,typ;
		scanf("%d",&typ);
		if(typ==1){
			scanf("%d",&l);
			rep(j,1,k)scanf("%d",&a[l][j]);
			updateall(l);
		}else{
			scanf("%d%d",&l,&r);
			int ans=0;
			rep(id,0,(1<<k-1)-1){
				mm minmax = query(1,1,n,l,r,id);
				ans = max(ans, minmax.max-minmax.min);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}