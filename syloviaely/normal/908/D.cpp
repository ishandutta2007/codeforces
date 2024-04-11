#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int dp[1100][1100];
int n,pa,pb;
const int mo=1e9+7;
int wa,wb,ans;
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
void add(int &k1,long long k2){
	k1=(k1+k2)%mo;
}
int main(){
	scanf("%d%d%d",&n,&pa,&pb);
	wa=1ll*pa*quick((pa+pb)%mo,mo-2)%mo;
	wb=1ll*pb*quick((pa+pb)%mo,mo-2)%mo;
	dp[1][0]=1;
	for (int i=1;i<n;i++){
		for (int j=0;j<n;j++)
			if (j+i<n)
				add(dp[i][i+j],1ll*dp[i][j]*wb);
			else add(ans,1ll*dp[i][j]*(i+j)%mo*wb%mo);
		for (int j=0;j<n;j++)
			add(dp[i+1][j],1ll*dp[i][j]*wa);
	}
	int numb=quick((1-wa+mo)%mo,mo-2);
	for (int i=0;i<n;i++){
		int k1=n+i;
		int num=1ll*wb*k1%mo*numb%mo;
		int num2=1ll*wb*wa%mo*numb%mo*numb%mo;
		ans=(ans+1ll*(num+num2)%mo*dp[n][i])%mo;
	}
	printf("%d\n",ans);
}