#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5, LG = 24;
int n, m, i, arr[MN], p, I, x, y, w;
struct seg{int cnt[LG], inv;}st[3*MN];

void build(int i, int s, int e){
	if(s != e){
		build(2*i,s,(s+e)/2); build(2*i+1,(s+e)/2+1,e);
		for(p=LG-1;p>=0;p--) st[i].cnt[p]=st[2*i].cnt[p]+st[2*i+1].cnt[p];
	}
	else{
		for(p=LG-1;p>=0;p--)
			if((1<<p)&arr[s]) st[i].cnt[p]=1;
	}
}

void push(int i, int s, int e){
	for(int p=LG-1;p>=0;p--)
		if(st[i].inv&(1<<p)) st[i].cnt[p]=e-s+1-st[i].cnt[p];
	if(s!=e){st[2*i].inv^=st[i].inv; st[2*i+1].inv^=st[i].inv;}
	st[i].inv = 0;
}

void upd(int i, int s, int e, int ss, int se, int msk){
	if(st[i].inv) push(i,s,e);
	if(s >= ss && e <= se){
		st[i].inv ^= msk;
		push(i,s,e);
	}
	else{
		if((s+e)/2<ss){upd(2*i+1,(s+e)/2+1,e,ss,se,msk); push(2*i,s,(s+e)/2);}
		else if((s+e)/2>=se){upd(2*i,s,(s+e)/2,ss,se,msk); push(2*i+1,(s+e)/2+1,e);}
		else{upd(2*i+1,(s+e)/2+1,e,ss,se,msk); upd(2*i,s,(s+e)/2,ss,se,msk);}
		for(p=LG-1;p>=0;p--) st[i].cnt[p]=st[2*i].cnt[p]+st[2*i+1].cnt[p];
	}
}

long long qu(int i, int s, int e, int ss, int se){
	if(st[i].inv) push(i,s,e);
	if(s >= ss && e <= se){
		long long ret = 0;
		for(int p=LG-1;p>=0;p--) ret+=1LL*(1<<p)*st[i].cnt[p];
		return ret;
	}
	else if((s+e)/2 < ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2 >= se) return qu(2*i,s,(s+e)/2,ss,se);
	else return 1LL*qu(2*i,s,(s+e)/2,ss,se)+qu(2*i+1,(s+e)/2+1,e,ss,se);
}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	build(1, 1, n);
	for(scanf("%d",&m),i=0;i<m;i++){
		scanf("%d",&I);
		if(I==1) scanf("%d%d",&x,&y),printf("%lld\n",qu(1,1,n,x,y));
		else{
			scanf("%d%d%d",&x,&y,&w);
			upd(1,1,n,x,y,w);
		}
	}
	return 0;
}