#include <bits/stdc++.h>
using namespace std;

const int MN = 5005;
typedef long long ll;
ll dp[MN][MN], N, K, X, arr[MN], i;
typedef pair<ll,ll> pii;
struct pq{bool operator()(const pii&i,const pii&j){return i.first<j.first;}};
priority_queue<pii,vector<pii>,pq> q[MN];
void solve(){
        for(int j=1;j<=X;j++) dp[N+1][j]=-(1LL<<60);
        for(int j=0;j<=X;j++){
                if(dp[N+1][j]>=0)q[j].push({dp[N+1][j],N+1});
        }
        for(int i=N;i>=1;i--){
                for(int j=0;j<X;j++){
                        while(q[j].size()&&q[j].top().second>i+K) q[j].pop();
                        if(q[j].size()) dp[i][j+1]=q[j].top().first;
                        else dp[i][j+1]=-(1LL<<60);
                }
                dp[i][0]=-(1LL<<60);
                for(int j=1;j<=X;j++) dp[i][j]+=arr[i];
                for(int j=0;j<=X;j++){
                        if(dp[i][j]>=0) q[j].push({dp[i][j],i});
                }
        }
}
int main(){
        for(scanf("%lld%lld%lld",&N,&K,&X),i=1;i<=N;i++)
                scanf("%lld",&arr[i]);
        solve();
        ll ans = -(1LL<<60);
        for(i=1;i<=K;i++) ans = max(ans, dp[i][X]);
        if(ans<0) printf("-1\n");
        else printf("%lld\n",ans);
        return 0;
}