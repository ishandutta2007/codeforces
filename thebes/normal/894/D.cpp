#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e6+6;
vector<ll> arr[MN][2], sum[MN][2];
ll N, M, p[MN], x, y, w, ans, cnt, i, last, d;

void build(ll n){
	for(int i=0;i<2;i++){
		if(2*n+i > N) continue;
		build(2*n+i);
		for(auto v : arr[2*n+i][0])
			arr[n][i].push_back(v+p[2*n+i]);
		for(auto v : arr[2*n+i][1])
			arr[n][i].push_back(v+p[2*n+i]);
		arr[n][i].push_back(p[2*n+i]);
		sort(arr[n][i].begin(), arr[n][i].end());
		for(int j=0;j<arr[n][i].size();j++)
			sum[n][i].push_back((j)?sum[n][i][j-1]+arr[n][i][j]:arr[n][i][j]);
	}
}

int main(){
	for(scanf("%lld%lld",&N,&M),i=1;i<=N-1;i++)
		scanf("%lld",&p[i+1]);
	build(1);
	for(i=0;i<M;i++){
		scanf("%lld%lld",&x,&y); w = y;
		for(int j=0;j<2;j++){
			int pos=upper_bound(arr[x][j].begin(),arr[x][j].end(),y)-arr[x][j].begin();
			if(pos == 0) continue;
			cnt += pos; ans += sum[x][j][pos-1];
		}
		last = x&1; y -= p[x]; d += p[x];  x /= 2; 
		while(x && y >= 0){
			cnt++; ans += d;
			int pos=upper_bound(arr[x][!last].begin(),arr[x][!last].end(),y)-arr[x][!last].begin();
			if(pos != 0){
				cnt += pos; ans += sum[x][!last][pos-1]+pos*d;
			}
			last = x&1; y -= p[x]; d += p[x]; x/=2;
		}
		printf("%lld\n",cnt*w-ans+w);
		ans = cnt = d = 0;
	}
	return 0;
}