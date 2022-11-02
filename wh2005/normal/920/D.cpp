#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int n,k,v,a[5009],sum;
int dp[5009][5009],las[5009][5009];
int flag[5009];

int main(){
	sum=0;
	scanf("%d%d%d",&n,&k,&v);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),sum+=a[i];
		if(a[i]==v){
			printf("YES\n");
			return 0;
		}
	} 
	if(sum<v){
		printf("NO\n");
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	memset(las,-1,sizeof(las));
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=5000;j>=0;j--) dp[i+1][j]=dp[i][j],las[i+1][j]=las[i][j];
		for(int j=5000;j>=0;j--){
			if(dp[i][j]!=-1){
				if(dp[i+1][(j+a[i+1])%k]==-1||dp[i+1][(j+a[i+1])%k]<dp[i][j]+a[i+1])
					dp[i+1][(j+a[i+1])%k]=dp[i][j]+a[i+1],las[i+1][(j+a[i+1])%k]=i;
			}
		}
	}
	if(dp[n][v%k]==-1){printf("NO\n");return 0;}
	printf("YES\n"); 
	int t=n,p=v%k;
	t=las[t][p],p=(p-a[t+1]%k+k)%k;
	while(t!=-1){
		flag[t+1]=1;
		t=las[t][p],p=(p-a[t+1]%k+k)%k;	
	}
	int pos=las[n][v%k]+1;
	if(!pos){
		for(int i=2;i<=n;i++)
			if(a[i]) printf("%d %d %d\n",(a[i]%k==0?(a[i]/k):(a[i]/k+1)),i,1);
		if(v/k) printf("%d %d %d\n",v/k,1,2);
		return 0;	
	}
	for(int i=1;i<=n;i++)
		if(flag[i]&&i!=pos){
			if(a[i]) printf("%d %d %d\n",(a[i]%k==0?(a[i]/k):(a[i]/k+1)),i,pos);
			a[pos]+=a[i];
		}
	if(a[pos]==v) return 0;
	if(a[pos]>v){
		if((a[pos]-v)/k) printf("%d %d %d\n",(a[pos]-v)/k,pos,pos%n+1);
		return 0;
	}		
	int q=0;
	for(int i=1;i<=n;i++)
		if(!flag[i]){
			if(!q) q=i;
			else{
				if(a[i]) printf("%d %d %d\n",(a[i]%k==0?(a[i]/k):(a[i]/k+1)),i,q);
			}
		}
	if((v-a[pos])/k) printf("%d %d %d\n",(v-a[pos])/k,q,pos);	
	return 0;
}