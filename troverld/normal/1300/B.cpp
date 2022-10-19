#include<bits/stdc++.h>
using namespace std;
int T,n,num[200100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n*2;i++)scanf("%d",&num[i]);
		sort(num,num+n*2);
		printf("%d\n",num[n]-num[n-1]);
	}
	return 0;
}