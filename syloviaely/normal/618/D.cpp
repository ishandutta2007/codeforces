#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int dp[210000],x,y,n,len,p[210000],w1,w2,pd[210000],d[210000];
void ade(int k1, int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len; d[k1]++;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void treedp(int k1,int k2){
	int num=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j==k2) continue;
		treedp(j,k1); dp[k1]+=dp[j]; num+=pd[j];
	}
	if (num==0) dp[k1]++,pd[k1]=1; else if (num>=2) pd[k1]=0,dp[k1]-=1; else pd[k1]=1;
}
int main(){
	scanf("%d%d%d",&n,&w1,&w2);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	if (w1>w2){
		long long ans=1ll*w2*(n-1);
		for (int i=1;i<=n;i++) if (d[i]==n-1) {ans+=w1-w2; break;}
		printf("%I64d\n",ans); return 0;
	}
	treedp(1,0); int ans=dp[1];
	printf("%I64d\n",1ll*(ans-1)*w2+1ll*(n-ans)*w1);
}