#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,r,c[(1<<18)+5];
int main(){
	scanf("%d%d",&n,&r);
	double sum=0;
	rep(i,0,(1<<n)-1)scanf("%d",&c[i]),sum+=c[i];
	printf("%.20f\n",sum/(1<<n));
	rep(_,1,r){
		int z,g;
		scanf("%d%d",&z,&g);
		sum-=c[z];
		c[z]=g;
		sum+=c[z];
		printf("%.20f\n",sum/(1<<n));
	}
	return 0;
}