#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5+5;
ll dif[MN], N, Q, i, x, y, arr[MN], ans, c;
vector<ll> cnt;

int main(){
	for(scanf("%lld%lld",&N,&Q),i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	sort(arr+1,arr+N+1);
	for(i=1;i<=Q;i++){
		scanf("%lld%lld",&x,&y);
		dif[x]++; dif[y+1]--;
	}
	for(i=1;i<=N;i++){
		c += dif[i];
		cnt.push_back(c);
	}
	sort(cnt.begin(),cnt.end());
	for(i=1;i<=N;i++)
		ans+=cnt[i-1]*arr[i];
	printf("%lld\n",ans);
	getchar(); getchar();
}