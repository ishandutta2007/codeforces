#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long s,n,k;
		scanf("%Ld%Ld%Ld",&s,&n,&k);
		if(s==k)puts("YES");
        else if(k > s)puts("NO");
		else if((n/k)*2*k<=s-n%k)puts("NO");
		else puts("YES");
	} 
	return 0;
}