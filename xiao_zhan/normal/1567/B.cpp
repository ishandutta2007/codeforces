#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[300500];

int main(){
	for(i=1;i<=300000;i++){
		f[i]=(f[i-1]^i);
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(f[n-1]==m){
			printf("%d\n",n);continue;
		}
		if(f[n]==m){
			printf("%d\n",n+2);continue;
		}
		printf("%d\n",n+1);
	}
}