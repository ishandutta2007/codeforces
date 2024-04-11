#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[17][2][2];
int len,x[17];
char ch[200];
long long init(){
	scanf("%s",ch+1); int n=strlen(ch+1); long long ans=0;
	for (int i=1;i<=n;i++)
		if (ch[i]>='0'&&ch[i]<='9') ans=ans*16+ch[i]-'0';
		else ans=ans*16+ch[i]-'a'+10;
	return ans;
}
long long solve(long long n){
	for (int i=0;i<=15;i++){
		x[i]=n%16; n/=16;
	}
//	for (int i=0;i<=15;i++) cout<<x[i]<<" "; cout<<endl;
	long long num=0;
	for (int now=0;now<16;now++){
		memset(dp,0x00,sizeof dp); dp[16][1][0]=1;
		int where1=now/4,where2=(1<<(now%4));
		for (int i=15;i>=0;i--){
		//	if (now==4) cout<<dp[i+1][0][0]<<" "<<dp[i+1][0][1]<<" "<<dp[i+1][1][0]<<" "<<dp[i+1][1][1]<<endl;
			for (int j=0;j<=now;j++){
				if (i==where1&&(j&where2)==0) continue;
				if (j==now){
					dp[i][0][1]+=dp[i+1][0][1]+dp[i+1][0][0];
					if (j<x[i])
						dp[i][0][1]+=dp[i+1][1][1]+dp[i+1][1][0];
					else if (j==x[i])
						dp[i][1][1]+=dp[i+1][1][1]+dp[i+1][1][0];
				} else {
					dp[i][0][0]+=dp[i+1][0][0];
					dp[i][0][1]+=dp[i+1][0][1];
					if (j<x[i]){
						dp[i][0][1]+=dp[i+1][1][1];
						dp[i][0][0]+=dp[i+1][1][0];
					}else if (j==x[i]){
						dp[i][1][1]+=dp[i+1][1][1];
						dp[i][1][0]+=dp[i+1][1][0];
					}
				}
			}
		}
	//	cout<<"fa "<<now<<" "<<dp[0][0][1]<<" "<<dp[0][1][1]<<endl; 
		num+=dp[0][0][1]+dp[0][1][1];
	}
	return num;
}
int main(){
	int q; scanf("%d",&q);
	for (;q;q--){
		long long l=init(),r=init();
		printf("%I64d\n",solve(r)-solve(l-1));
	}
	return 0;
}