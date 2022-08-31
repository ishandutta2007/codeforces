#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int p[210000],n,len,dp[210000],w[210000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void treedp1(int k1,int k2,int k3){
	int num=0; w[k1]=0;
	if (k3==0) dp[k1]=1e9; else dp[k1]=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			treedp1(j,k1,k3^1); 
			if (k3==0) dp[k1]=min(dp[k1],dp[j]); else dp[k1]=dp[k1]+dp[j];
			w[k1]=w[k1]+w[j];
		}
	}
	if (w[k1]==0){w[k1]=1; dp[k1]=1;}
}
void treedp2(int k1,int k2,int k3){
	int num=0; w[k1]=0;
	if (k3==0) dp[k1]=0; else dp[k1]=1e9;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			treedp2(j,k1,k3^1); 
			if (k3==0) dp[k1]=dp[k1]+dp[j]-1; else dp[k1]=min(dp[k1],w[j]-dp[j]);
			w[k1]=w[k1]+w[j];
		}
	}
	if (w[k1]==0){w[k1]=1; dp[k1]=1;} else if (k3==0) dp[k1]++; else dp[k1]=w[k1]-dp[k1];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	treedp1(1,0,0);
	cout<<w[1]-dp[1]+1<<" ";
	treedp2(1,0,0);
	cout<<w[1]-dp[1]+1<<endl;
}