#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=(signed)1000000007;
int a[3],l,r;
int minus_1(int nn){
	if(nn==1)	return 0;
	if(nn==2)	return 1;
	if(nn==0)	return 2;
}
int minus_2(int nn){
	if(nn==1)	return 2;
	if(nn==2)	return 0;
	if(nn==0)	return 1;
}
int n;
int memo[1000001][3];
int way(int i,int sum){
//	if(i==32505){
//		return memo[32505][sum]=
//		((long long)way(32504,minus_1(sum))*a[1]%MOD
//		+(long long)way(32504,minus_2(sum))*a[2]%MOD
//		+(long long)way(32504,sum)*a[0]%MOD)%MOD;
//	}
	if(i==0){
		if(sum==0)	return memo[0][0]=1;
		else	return memo[0][sum]=0;
	}
	if(memo[i][sum])	return memo[i][sum];
	return memo[i][sum]=
	((long long)way(i-1,minus_1(sum))*a[1]%MOD
	+(long long)way(i-1,minus_2(sum))*a[2]%MOD
	+(long long)way(i-1,sum)*a[0]%MOD)%MOD;
}
signed main(){
	cin>>n>>l>>r;
	a[0]=r/3-(l-1)/3;
	a[1]=(r+2)/3-(l+1)/3;
	a[2]=(r+1)/3-l/3;
//	way(32504,0),way(32504,1),way(32504,2);
//	way(65007,0),way(65007,1),way(65007,2);
//	way(97510,0),way(97510,1),way(97510,2);
//	way(130014,0),way(130014,1),way(130014,2);
//	way(162518,0),way(162518,1),way(162518,2);
//	way(195022,0),way(195022,1),way(195022,2);
	int ans=way(n,0);
	cout<<ans<<endl;
}
/*65008 1 3*/