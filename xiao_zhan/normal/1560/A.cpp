#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb[10500],it;

int main(){
	for(i=1;it<=1000;i++){
		if((i%10)==3||(i%3)==0){continue;}
		sb[++it]=i;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",sb[n]);
	}
}