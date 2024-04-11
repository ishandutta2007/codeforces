#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=3005;
int n,A[N],B[N],C[N],id[N],ans[N];
int brand(){return(rand()<<16)+(rand()<<1)+(rand()&1);}
int query(int k1,int k2){
	printf("? %d %d\n",k1,k2);fflush(stdout);
	int x;scanf("%d",&x);return x;
}
int get(int x){
	int ans=(1<<11)-1;
	rep(i,0,10){
		int y=A[i]==x?B[i]:A[i];
		ans&=query(x,y);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	while(1){
		int k1,k2;do k1=brand()%n+1,k2=brand()%n+1;while(k1==k2);
		int k3=query(k1,k2);
		rep(i,0,10)if(~k3>>i&1)A[i]=k1,B[i]=k2,C[i]=k3;
		rep(i,0,10)if(A[i]==0)goto naive;
		break;
		naive:;
	}
	rep(i,1,n)id[i]=i;
	rep(i,1,n)swap(id[i],id[brand()%i+1]);
	int x=get(id[1]),y=id[1];
	rep(i,2,n){
		if(query(y,id[i])==x){
			x=get(id[i]);
			y=id[i];
		}
	}
	rep(i,1,n){
		if(i==y)ans[i]=0;
		else ans[i]=query(i,y);
	}
	printf("! ");rep(i,1,n)printf("%d ",ans[i]);fflush(stdout);
	return 0;
}