#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define MP make_pair
typedef long long LL;
const int N = 100010;

int n,m,k,s,t,d,w;
LL dp[N][210];
multiset< pair<int, int> > S;
vector< pair<int, int> > ins[N], era[N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k){
		scanf("%d%d%d%d",&s,&t,&d,&w);
		ins[t].PB(MP(-w,-d));
		era[s].PB(MP(-w,-d));
	}
	for(int i=n;i;--i){
		for(auto e:ins[i]) S.insert(e);
		rep(j,0,m){
			dp[i][j] = S.empty() ? dp[i + 1][j]: dp[- (*S.begin()).second + 1][j] - (*S.begin()).first;
			if(j) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
		}
		for(auto e:era[i]) S.erase(S.lower_bound(e));
	}
	cout<<dp[1][m]<<endl;
	return 0;
}