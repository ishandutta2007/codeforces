#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x,y;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&x,&y);
		printf("%lld %lld\n",x*x,-y*y);
	}
	return 0;
}