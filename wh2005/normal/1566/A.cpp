#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T;ll n,s;




int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&s);
		if(n==1){
			printf("%lld\n",s);
			continue;
		}
		ll k=(n+1)/2;
		printf("%lld\n",s/(n-k+1));
	}
	return 0;
}