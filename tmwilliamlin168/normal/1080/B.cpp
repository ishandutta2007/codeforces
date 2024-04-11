#include<cstdio>
using namespace std;
int q,l,r;
int Calc(int n){
	if(n&1)
		return -(n+1)/2;
	else
		return n/2;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",Calc(r)-Calc(l-1));
	}
}