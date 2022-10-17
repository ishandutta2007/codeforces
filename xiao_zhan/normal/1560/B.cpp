#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb[10500],it;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&i,&j,&k);
		if(i>j){swap(i,j);}
		if(i+i>j){puts("-1");continue;}
		n=j-i;
		if(k<=n){
			printf("%d\n",k+n);continue;
		}
		if(k>n&&k<=n+n){
			printf("%d\n",k-n);continue;
		}
		puts("-1");
	}
}