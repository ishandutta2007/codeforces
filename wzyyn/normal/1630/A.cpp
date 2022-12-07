#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if (!k){
		for (int i=0;i<n/2;i++)
			printf("%d %d\n",i,n-1-i);
	}
	else if (k!=n-1){
		printf("%d %d\n",0,n-k-1);
		printf("%d %d\n",k,n-1);
		for (int i=1;i<n/2;i++)
			if (i!=k&&i!=n-k-1)
				printf("%d %d\n",i,n-1-i);
	}
	else if (n==4) puts("-1");
	else{
		printf("%d %d\n",0,2);
		printf("%d %d\n",1,n-3);
		printf("%d %d\n",n-2,n-1);
		for (int i=3;i<n/2;i++)
			printf("%d %d\n",i,n-1-i);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
0 i j (2^n-1)

*/