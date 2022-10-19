#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n , cost[5] , num[5] , ans = 1e18;

signed main() {
	cin>>n;
	n = n % 4;
	for(int i = 1;i <= 3;i ++) cin>>cost[i];
	 for(int i = 0;i <= 3;i ++) {
	 	for(int j = 0;j <= 3;j ++) {
	 		for(int k = 0;k <= 3;k ++) {
	 			int tot = i+ j*2 + k*3 + n;
	 			if(tot % 4== 0) {
	 				ans = min(ans , i*cost[1] + j*cost[2] + k*cost[3]);
				 }
			 }
		 }
	 }
	 cout<<ans<<endl;
}