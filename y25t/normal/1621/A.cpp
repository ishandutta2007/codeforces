#include<bits/stdc++.h>
#define N 45

int T;

int n,k;

bool ans[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(2*k-1>n){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans[i][j]=0;
		for(int i=1;i<=k;i++)
			ans[2*i-1][2*i-1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				putchar(ans[i][j]?'R':'.');
			puts("");
		}
	}
}