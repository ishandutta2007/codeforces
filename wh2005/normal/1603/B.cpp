#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T;
ll n;


int main(){
	scanf("%d",&T);
	while(T--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll n;
		if(x>y) n=x+y;
		else n=y-y%x/2;
		printf("%lld\n",n);
	}
	return 0;
}