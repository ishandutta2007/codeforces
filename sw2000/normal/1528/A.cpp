#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 10;

int n,w[N][2];
ll dp[N][2];
vi edg[N];

void dfs(int u,int f){
    dp[u][0]=dp[u][1]=0;
    for(auto v:edg[u])if(v!=f){
        dfs(v,u);
        for(int i=0;i<2;i++){
            dp[u][i]+=max(dp[v][0]+abs(w[u][i]-w[v][0]),dp[v][1]+abs(w[u][i]-w[v][1]));
        }
    }
}
ll solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i][0]>>w[i][1];
    }
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs(1,0);
    return max(dp[1][0],dp[1][1]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--){
        cout<<solve()<<endl;
        for(int i=1;i<=n;i++)edg[i].clear();
	}
}