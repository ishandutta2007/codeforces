#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
LL p[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
LL pq(LL n){
	LL ans=1;
	if (n>42) return -1;
	for (int i=0;i<13;++i){
		LL j=1;
		while(p[i]*j<=n){
			j*=p[i];
		}
		ans*=j; 
	}
	return ans;
}

int main(){
	LL x,y;
	scanf("%lld%lld",&x,&y);
	if (pq(y)!=-1&&(x+1)%pq(y)==0){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}