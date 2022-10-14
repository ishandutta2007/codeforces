#include <bits/stdc++.h>
using namespace std;
int Ask(int a,int b){
	printf("? %i %i\n",a,b);
	fflush(stdout);
	int ret;
	scanf("%i",&ret);
	return ret;
}
int main(){
	int t;
	for(scanf("%i",&t);t;t--){
		int ans=0;
		for(int i=0;i<30;i++)if(Ask((1<<i)-ans,(1<<i)-ans+(1<<(i+1)))==(1<<(i+1)))ans+=(1<<i);
		printf("! %i\n",ans);
		fflush(stdout);
	}
	return 0;
}