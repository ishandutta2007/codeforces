//  Created by  on 2018/8/19.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,a[1000] = {0};
int dp[710][710][3] = {0};
ll gcd(ll a,ll b){
	return b == 0?a:gcd(b,a%b);
}
int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i][i][2] = 1;
		dp[i][i][0] = (gcd(a[i],a[i-1])>1);
		dp[i][i][1] = (gcd(a[i],a[i+1])>1);
	}
	for(int le = 2;le<=n;le++){
		for(int l = 1;l<=n;l++){
			int r = l+le-1;
			if(r>n)break;
			for(int rt = l+1;rt<r;rt++){
				if(dp[l][rt-1][1] && dp[rt+1][r][0]){
					dp[l][r][2] = 1;
					dp[l][r][0] |= (gcd(a[l-1],a[rt])>1);
					dp[l][r][1] |= (gcd(a[r+1],a[rt])>1);
				}
				if(dp[l][r][0] && dp[l][r][1] && dp[l][r][2]){
					break;
				}
			}
			if(dp[l+1][r][0]){
				dp[l][r][2] = 1;
				dp[l][r][0] |= (gcd(a[l-1],a[l])>1);
				dp[l][r][1] |= (gcd(a[r+1],a[l])>1);
			}
			if(dp[l][r-1][1]){
				dp[l][r][2] = 1;
				dp[l][r][0] |= (gcd(a[l-1],a[r])>1);
				dp[l][r][1] |= (gcd(a[r+1],a[r])>1);
			}
		}
	}
	if(dp[1][n][2]){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}