#include <bits/stdc++.h>
using namespace std;
char ch[1100];
int K,n,f[1100],dp[1100];
const int mo=1e9+7;
int main(){
	scanf("%s",ch+1);
	scanf("%d",&K); n=strlen(ch+1);
	if (K==0){
		printf("%d\n",1); return 0;
	}
	f[1]=0;
	for (int i=2;i<=n;i++) f[i]=f[__builtin_popcount(i)]+1;
	int pre=0; dp[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=n;j;j--) dp[j]=(dp[j]+dp[j-1])%mo;
		if (ch[i]=='1') dp[pre]++;
		pre+=ch[i]-'0';
	}
	dp[pre]++;
	int ans=0;
	for (int i=1;i<=n;i++) if (f[i]==K-1){
		ans=(ans+dp[i])%mo;
	}
	if (K==1) ans=(ans-1+mo)%mo;
	cout<<ans<<endl; return 0;
}