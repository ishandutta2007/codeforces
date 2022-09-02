// author: xay5421
// created: Fri Jun  4 23:50:07 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=(1<<20)+5;
int K,ind,id[N],_id[N],t[N];
char s[N];
void upd(int k1){
	if(k1<(1<<(K-1))){
		if(s[id[k1]]=='?')t[k1]=t[k1*2]+t[k1*2+1];
		else t[k1]=t[k1*2+(s[id[k1]]=='1')];
	}else{
		t[k1]=s[id[k1]]=='?'?2:1;
	}
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		upd(k1);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void up(int k1){
	while(k1){
		upd(k1);
		k1>>=1;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%s",&K,s+1);
	int Q;
	scanf("%d",&Q);
	per(i,K-1,0){
		rep(j,1<<i,(1<<(i+1))-1)id[j]=++ind,_id[ind]=j;
	}
	bud(1,1,1<<(K-1));
	while(Q--){
		int k1;
		char k2[2];
		scanf("%d%s",&k1,k2);
		s[k1]=k2[0];
		up(_id[k1]);
		printf("%d\n",t[1]);
	}
	return 0;
}