#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll A[500100];
ll S[500100];
int D[500100];
vector<ll> comp;

int Dm[500100], Dp[500100], Ds[500100];
void upd(int B[], int idx, int val, int dir) {
	idx++;
	if (dir>0) {
		while(idx<=comp.size()){
			B[idx] = max(B[idx],val);
			idx += idx&-idx;
		}
	}
	else {
		while(idx) {
			B[idx] = max(B[idx],val);
			idx -= idx&-idx;
		}
	}
}
int getv(int B[], int idx, int dir) {
	idx++;
	int ans = -INF;
	if (dir>0) {
		while(idx<=comp.size()){
			ans = max(B[idx],ans);
			idx += idx&-idx;
		}
	}
	else {
		while(idx) {
			ans = max(B[idx],ans);
			idx -= idx&-idx;
		}
	}
	return ans;
}

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		comp.clear();
		scanf("%d",&N);
		comp.push_back(0);
		S[0] = 0;
		for (int i=1;i<=N;i++) {
			scanf("%lld",&A[i]);
			S[i] = S[i-1]+A[i];
			comp.push_back(S[i]);
		}
		sort(comp.begin(),comp.end());
		comp.erase(unique(comp.begin(),comp.end()),comp.end());
		for (int i=0;i<=N;i++) {
			S[i] = lower_bound(comp.begin(),comp.end(),S[i])-comp.begin();
		}
		for (int i=0;i<=comp.size();i++) {
			Dm[i] = Dp[i]= Ds[i] = -INF;
		}
		D[0] = 0;
		upd(Dp,S[0]-1,D[0],-1);
		upd(Dm,S[0]+1,D[0],1);
		Ds[S[0]] = max(Ds[S[0]],D[0]);
		for (int i=1;i<=N;i++) {
			D[i] = max({getv(Dp,S[i],1)-i,getv(Dm,S[i],-1)+i,Ds[S[i]]});
			upd(Dp,S[i]-1,D[i]+i,-1);
			upd(Dm,S[i]+1,D[i]-i,1);
			Ds[S[i]] = max(Ds[S[i]],D[i]);
//			printf("%d: %d\n",i,D[i]);
		}
		printf("%d\n",D[N]);
	}

	return 0;
}