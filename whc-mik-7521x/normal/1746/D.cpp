#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n,k,cnt[N],sum[N],fa[N],dp[N][2];
vector<int> ed[N];
void dfs(int u) {
    vector<long long>vec(0);
    dp[u][1]=sum[u]*(cnt[u]+1);
    dp[u][0]=sum[u]*cnt[u];
    if(!ed[u].size())return;
    for(int v:ed[u]){
        cnt[v]=cnt[u]/ed[u].size();
        dfs(v);
        vec.push_back(dp[v][1]-dp[v][0]);
        dp[u][0]+=dp[v][0];
        dp[u][1]+=dp[v][0];
    }
    sort(begin(vec),end(vec));
    reverse(vec.begin(),vec.end());
    int rst=cnt[u]%ed[u].size();
    for(int i=0;i<rst;++i)dp[u][0]+=vec[i],dp[u][1]+=vec[i];
    dp[u][1]+=vec[rst];
}
int main() {
    int t;
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i=1;i<=n;i++) ed[i].resize(0);
        for (int i=2;i<=n;i++)cin>>fa[i],ed[fa[i]].push_back(i);
        for (int i=1;i<=n;i++)cin>>sum[i];
        cnt[1] = k, dfs(1);
        cout<<dp[1][0]<<endl;
    }
	return 0;
}