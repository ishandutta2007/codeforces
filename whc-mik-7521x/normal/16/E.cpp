#include<bits/stdc++.h>
using namespace std;
long double dp[1<<18],a[20][20];
int n,bit[1<<18];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			scanf("%Lf",&a[i][o]);
		}
	}
	dp[0]=1;
	int ma=1<<n;
	for(int i=1;i<ma;i++){
		bit[i]=bit[i^(i&-i)]+1;
	}
	for(int i=0;i<ma;i++){
		bit[i]=n-bit[i];
	}
	for(int i=1;i<ma;i++){
		for(int o=1,o1=1;o<ma;o<<=1,o1++){
			for(int j=1,j1=1;j<ma;j<<=1,j1++){
				if(o!=j&&(o&i)==o&&(j&i)==0){
					dp[i]+=1.0*dp[i^o]*a[j1][o1]/(bit[i^o]*(bit[i^o]-1)/2);
				}
			}
		}
	}
	for(int i=1;i<ma;i<<=1){
		printf("%Lf ",dp[(ma-1)^i]);
	}
	return 0;
}