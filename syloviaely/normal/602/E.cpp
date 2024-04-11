#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long double dp[110000];
int x[110],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	if (m==1){
		printf("%.11lf\n",1.0); return 0;
	}
	dp[0]=1; int tot=0;
	for (int now=1;now<=n;now++){
		tot+=m; long double k1=0;
		for (int i=1;i<=m;i++) k1+=dp[tot-i];
		for (int i=tot;i>=0;i--){
			dp[i]=k1; if (i-x[now]>=0) dp[i]-=dp[i-x[now]];
			dp[i]=dp[i]/(m-1); if (i==0) break;
			k1-=dp[i-1]; if (i-1-m>=0) k1+=dp[i-1-m];
		}
	//	cout<<"add "<<now<<endl; k1=0;
	//	for (int i=1;i<=tot;i++) printf("%.3lf ",(double)dp[i]),k1+=dp[i]; cout<<endl;
	//	cout<<(double)k1<<endl;
	}
	long double ans=0;
	tot=0;
	for (int i=1;i<=n;i++) tot+=x[i];
//	cout<<tot<<endl;
	for (int i=0;i<tot;i++) ans+=dp[i];
	printf("%.11lf\n",(double)ans*(m-1)+1);
	return 0;
}