#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll n,l,r,md,res,sb,m;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		sb=n/2+1;
		printf("%lld\n",m/sb);
	}
}