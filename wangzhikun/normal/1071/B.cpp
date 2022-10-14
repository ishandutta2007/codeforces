//  Created by WangZhikun on 2018/10/21.

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define PII pair<int,int>
using namespace std;
typedef long long ll;
ll n,k,dp[2020][2020],dp2[2020][2020];
char mp[2020][2020],ans[4020];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>mp[i];
	}
	dp[0][0] = -k;
	if(mp[0][0] != 'a')dp[0][0]+=1;
	for(int dist = 1;dist<=n*2-2;dist++){
		vector<ll> cucu;
		for(int x = 0;x<=dist;x++){
			int y = dist-x;
			if(x<0 || x>=n||y<0 || y>=n)continue;
			if(x>0 && y>0){
				if(min(dp[x-1][y],dp[x][y-1])+(mp[x][y]!='a')<=0){
					dp[x][y] = min(dp[x-1][y],dp[x][y-1])+(mp[x][y]!='a');
				}else{
					dp[x][y] = min(dp[x-1][y],dp[x][y-1])*130+mp[x][y];
					cucu.push_back(min(dp[x-1][y],dp[x][y-1])*130+mp[x][y]);
				}
			}
			if(x>0 && y<=0){
				if(dp[x-1][y]+(mp[x][y]!='a')<=0){
					dp[x][y] = dp[x-1][y]+(mp[x][y]!='a');
				}else{
					dp[x][y] = dp[x-1][y]*130+mp[x][y];
					cucu.push_back(dp[x-1][y]*130+mp[x][y]);
				}
			}
			if(x<=0 && y>0){
				if(dp[x][y-1]+(mp[x][y]!='a')<=0){
					dp[x][y] = dp[x][y-1]+(mp[x][y]!='a');
				}else{
					dp[x][y] = dp[x][y-1]*130+mp[x][y];
					cucu.push_back(dp[x][y-1]*130+mp[x][y]);
				}
			}
		}
		sort(cucu.begin(),cucu.end());
		for(int x = 0;x<=dist;x++){
			int y = dist-x;
			if(x<0 || x>=n||y<0 || y>=n)continue;
			if(dp[x][y]>0){
				dp[x][y] = lower_bound(cucu.begin(), cucu.end(), dp[x][y])-cucu.begin()+3;
			}
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<'\t';
		}
		cout<<endl;
	}*/
	int x = n-1,y = n-1,id = n*2-2;
	while(!(x == 0 && y == 0)){
		ans[id] = mp[x][y];
		if(dp[x][y]<=0)ans[id] = 'a';
		if(y == 0 || (x!=0 && dp[x-1][y]<=dp[x][y-1])){
			x-=1;
		}else{
			y-=1;
		}
		--id;
	}
	ans[id] = mp[x][y];
	if(dp[x][y]<=0)ans[id] = 'a';
	cout<<ans<<endl;
	return 0;
}