#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,sb;


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		if(n&1){
			k=n-n/2;
			if(k>=m){
				printf("%d\n",n-k);
			}
			else{
				printf("%d\n",n-m);
			}
		}
		else{
			n--;
			k=n-n/2;
			if(k>=m){
				printf("%d\n",n-k);
			}
			else{
				printf("%d\n",n+1-m);
			}
		}
	}
}