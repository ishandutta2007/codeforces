// author: xay5421
// created: Sun Aug 29 22:36:56 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
int calc(int k1,int k2){
	if((k1&1)!=(k2&1))return -1;
	if(k1==0&&k2==0)return 0;
	if(k1==k2)return 1;
	if(k1<k2)swap(k1,k2);
	if((k1&1)==(k2&1))return 2;
	assert(0);
}
int main(){
	scanf("%d",&T);
	while(T--){
		int c,d;
		scanf("%d%d",&c,&d);
		printf("%d\n",calc(c,d));
	}
	return 0;
}