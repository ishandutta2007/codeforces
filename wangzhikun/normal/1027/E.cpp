//  Created by  on 2018/8/18.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll mod = 998244353;

ll n,lk,dp[25000001] = {0},ids[4][520],actu[510] = {0};

int getid(int i,int j,int k){
	if(j>i || k>j || i== 0 || j == 0 || k == 0)return 25000000;
	return ids[2][i]+ids[1][j]+k;
}
int main() {
	read(n);read(lk);
	for(int i=0;i<510;i++)ids[0][i] = i;
	for(int i=1;i<510;i++)ids[1][i] = ids[1][i-1]+ids[0][i];
	for(int i=1;i<510;i++)ids[2][i] = ids[2][i-1]+ids[1][i];
	dp[getid(1,1,1)] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=j;k++){
				dp[getid(i,j,1)] += dp[getid(i-1,j,k)];
			}
			dp[getid(i,j,1)]%=mod;
			for(int k=2;k<=j;k++){
				dp[getid(i,j,k)] = dp[getid(i-1,j,k-1)];
			}
			dp[getid(i,j,j)] += dp[getid(i-1,j-1,j-1)];
		}
	}
	//for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)for(int k=1;k<=j;k++)cout<<i<<' '<<j<<' '<<k<<' '<<dp[getid(i, j, k)]<<endl;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=j;k++){
			actu[j]+=dp[getid(n,j,k)];
		}
		actu[j]%=mod;
		//cout<<actu[j]<<endl;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(i*j<lk){
			ans = (ans+(actu[i]*actu[j])%mod)%mod;
		}
	}
	cout<<(ans*2)%mod<<endl;
	return 0;
}