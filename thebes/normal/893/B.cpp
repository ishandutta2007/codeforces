#include <bits/stdc++.h>
using namespace std;

int N, i, x, ans;

int main(){
	scanf("%d",&N);
	for(i=1;i<12;i++){
		x = ((1<<i)-1)*(1<<(i-1));
		if(N%x==0) ans=x;
	}
	printf("%d\n",ans);
	return 0;
}