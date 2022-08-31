#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[210000][6],ans;
int num[210000][6];
struct bian{
	int next,point;
}b[410000];
int n,len,K,p[210000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void treedp(int k1,int k2){
	dp[k1][0]=0; num[k1][0]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			treedp(j,k1);
			for (int a=0;a<K;a++)
				for (int b=0;b<K;b++){
					ans+=num[j][b]*dp[k1][a]+num[k1][a]*dp[j][b];
					if (a+b>=K) ans+=1ll*num[j][b]*num[k1][a];
					ans+=1ll*num[j][b]*num[k1][a];
				}
			for (int a=0;a<K;a++){
				dp[k1][(a+1)%K]+=dp[j][a]+(a+1==K)*num[j][a];
				num[k1][(a+1)%K]+=num[j][a];
			}
		}
	}
//	cout<<"dp "<<k1<<" "<<ans<<endl;
//	for (int i=0;i<K;i++) cout<<dp[k1][i]<<" "; cout<<endl;
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	treedp(1,0);
	printf("%I64d\n",ans);
	return 0;
}