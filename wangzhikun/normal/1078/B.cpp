#include <cmath>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
int dp[110][10100] = {0},a[120] = {0},c,n,cnt = 0;
int main() {
	dp[0][0] = 1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		if(!a[c])++cnt;
		a[c]++;
	}
	for(int j=1;j<=100;j++){
		for(int l = 100;l>=1;l--)for(int i=10050;i>=0;i--)for(int k=1;k<=a[j];k++)if(i>=k*j&&l>=k)dp[l][i]+=dp[l-k][i-k*j];
	}
	int ans = 0;
	for(int j=1;j<=100;j++){
		for(int k=1;k<=a[j];k++){
			//cout<<k<<' '<<j*k<<' '<<dp[k][j*k]<<endl;
			if(dp[k][j*k] == 1){
				ans = max(ans,k);
				if(k == a[j] && cnt == 2)ans = n;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}