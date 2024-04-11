#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
int N, Q, i, x, y, w;
ll ns, ps, arr[MN], dif[MN];

ll solve(){
	ll tot = arr[1]+ps;
	return ceil(tot/(long double)2);
}

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%lld",&arr[i]);
		dif[i] = arr[i]-arr[i-1];
		if(i!=1){
			if(dif[i]>=0) ps += dif[i];
		}
	}
	printf("%lld\n",solve());
	for(scanf("%d",&Q);Q;Q--){
		scanf("%d%d%d",&x,&y,&w);
		if(x==1){
			arr[1] += w;
			if(y+1<=N){
				if(dif[y+1]>=0) ps -= dif[y+1];
				dif[y+1] -= w;
				if(dif[y+1]>=0) ps += dif[y+1];
			}
		}
		else{
			if(dif[x]>=0) ps -= dif[x];
			dif[x] += w;
			if(dif[x]>=0) ps += dif[x];
			if(y+1<=N){
				if(dif[y+1]>=0) ps -= dif[y+1];
				dif[y+1] -= w;
				if(dif[y+1]>=0) ps += dif[y+1];
			}
		}
		printf("%lld\n",solve());
	}
	return 0;
}