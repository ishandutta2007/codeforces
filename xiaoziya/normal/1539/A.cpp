#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,x,t,T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&x,&t);
		int v=t/x;
		if(n<v)
			printf("%lld\n",1ll*(n-1)*n/2);
		else printf("%lld\n",1ll*(v-1)*v/2+1ll*(n-v)*v);
	}
	return 0;
}