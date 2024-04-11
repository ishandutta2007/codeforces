#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+5;
int N, i, j, A, B, flag, ans;

int main(){
	for(scanf("%d%d%d",&N,&A,&B);i*A<=N;i++){
		flag = max(flag, (int)!((N-i*A)%B));
		if((N-i*A)%B==0) ans=i;
	}
	if(!flag) printf("-1\n");
	else{
		for(i=0;i<ans;i++){
			for(j=i*A;j<(i+1)*A-1;j++)
				printf("%d ",j+2);
			printf("%d ",i*A+1);
		}
		flag = ans*A;
		ans = (N-ans*A)/B;
		for(i=0;i<ans;i++){
			for(j=i*B;j<(i+1)*B-1;j++)
				printf("%d ",j+2+flag);
			printf("%d ",i*B+1+flag);
		}
	}
	return 0;
}