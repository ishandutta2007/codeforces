// author: xay5421
// created: Sun Aug 29 23:06:20 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,K;
int and_(int i,int j){
	printf("and %d %d\n",i,j);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int or_(int i,int j){
	printf("or %d %d\n",i,j);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int a[4][4],o[4][4],ans[10005];
int main(){
	scanf("%d%d",&n,&K);
	rep(i,1,3)rep(j,i+1,3){
		a[i][j]=and_(i,j);
		o[i][j]=or_(i,j);
	}
	per(i,30,0){
		rep(w1,0,1)rep(w2,0,1)rep(w3,0,1)if((w1&w2)==(a[1][2]>>i&1)&&(w1&w3)==(a[1][3]>>i&1)&&(w2&w3)==(a[2][3]>>i&1)&&
(w1|w2)==(o[1][2]>>i&1)&&(w1|w3)==(o[1][3]>>i&1)&&(w2|w3)==(o[2][3]>>i&1)){
			ans[1]^=w1<<i;
			ans[2]^=w2<<i;
			ans[3]^=w3<<i;
			goto OK;
		}
		OK:;
	}
	rep(i,4,n){
		int w1=and_(1,i),w2=or_(1,i);
		ans[i]=(ans[1]&w1)|(~ans[1]&w2);
	}
	nth_element(ans+1,ans+K,ans+1+n);
	printf("finish %d",ans[K]);
	fflush(stdout);
	return 0;
}