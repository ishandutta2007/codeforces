#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,M=N*200;
int n,tag[M],lc[M],rc[M],ind;
int ans=0,root=0;
int low=0,high=1000000000;
int ask(int k1,int k2,int k3,int k4,int tags){
	if(!k1){
		return k4+tags;
	}
	tags+=tag[k1];
	if(k2==k3){
		return k4+tags;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)return ask(lc[k1],k2,mid,k4,tags);
	else return ask(rc[k1],mid+1,k3,k4,tags);
}
int query1(int k1,int k2,int k3,int k4,int tags){ // first=k4
	if(!k1){
		return k4-tags;
	}
	tags+=tag[k1];
	if(!lc[k1]){
		return k4-tags;
	}
	int mid=(k2+k3)>>1;
	if(/*mid+tags+tag[lc[k1]]*/ask(root,0,1000000000,mid,0)>=k4){
		return query1(lc[k1],k2,mid,k4,tags);
	}else{
		return query1(rc[k1],mid+1,k3,k4,tags);
	}
}
int query2(int k1,int k2,int k3,int k4,int tags){ // last=k4
	if(!k1){
		return k4-tags;
	}
	tags+=tag[k1];
	if(!lc[k1]){
		return k4-tags;
	}
	int mid=(k2+k3)>>1;
	if(/*mid+1+tags+tag[rc[k1]]*/ask(root,0,1000000000,mid+1,0)<=k4){
		return query2(rc[k1],mid+1,k3,k4,tags);
	}else{
		return query2(lc[k1],k2,mid,k4,tags);
	}
}
void deal(int&k1,int k2,int k3,int k4){
	if(!k1){
		k1=++ind;
	}
	if(k2==k3){
		return;
	}
	if(!lc[k1]){
		lc[k1]=++ind,rc[k1]=++ind;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid){
		deal(lc[k1],k2,mid,k4);
	}else{
		deal(rc[k1],mid+1,k3,k4);
	}
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		assert(k1);
		tag[k1]+=k6;
		return;
	}
	int mid=(k2+k3)>>1;
	add(lc[k1],k2,mid,k4,k5,k6),add(rc[k1],mid+1,k3,k4,k5,k6);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		{
			int x;
			scanf("%d",&x);
			if(x<low){
				add(root,0,1000000000,0,1000000000,-1);
				--low,--high;
			}else if(x>high){
				add(root,0,1000000000,0,1000000000,1);
				++low,++high;
			}else{
				int t1=query1(root,0,1000000000,x,0);
				int t2=query2(root,0,1000000000,x,0);
				if(t1>0){
					deal(root,0,1000000000,t1-1);
					add(root,0,1000000000,0,t1-1,1);
				}
				if(t2<1000000000){
					deal(root,0,1000000000,t2+1);
					add(root,0,1000000000,t2+1,1000000000,-1);
				}
				if(x>low)++low;
				if(x<high)--high;
			}
		}
		int K;
		scanf("%d",&K);
		while(K--){
			int x;
			scanf("%d",&x);
#ifndef xay54210
			x=(x+ans)%1000000001;
#endif
			printf("%d\n",ans=ask(1,0,1000000000,x,0));
		}
	}
	return 0;
}