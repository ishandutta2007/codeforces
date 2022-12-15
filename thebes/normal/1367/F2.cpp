#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int T, N, i, j, x, y, arr[MN], ans;
map<int,int> cnt, tcnt, dp, mx, mp;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N); tcnt.clear(), mp.clear();
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
			mp[arr[i]] = 0;
			tcnt[arr[i]]++;
		}
		ans = 0;
		cnt.clear(), dp.clear(), mx.clear();
		for(i=1;i<=N;i++){
			auto it=mp.lower_bound(arr[i]);
			int pre = -1;
			if(it!=mp.begin()){
				it--;
				pre = it->first;
			}
			mx[arr[i]]++; dp[arr[i]]++;
			if(pre!=-1&&tcnt[pre]==cnt[pre]){
				ans = max(ans, dp[pre]+1);
				mx[arr[i]] = max(mx[arr[i]], dp[pre]+1);
				if(cnt[arr[i]]==0) dp[arr[i]] = dp[pre]+1;
			}
			else{
				ans = max(ans, cnt[pre]+1);
				mx[arr[i]] = max(mx[arr[i]], cnt[pre]+1);
				if(cnt[arr[i]]==0) dp[arr[i]] = cnt[pre]+1;
			}
			cnt[arr[i]]++;
			ans = max(ans, mx[arr[i]]);
		}
		printf("%d\n",N-ans);
	}
	return 0;
}