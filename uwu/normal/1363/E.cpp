#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

vector<int> graph[MAXN];
ll cost[MAXN]; int val[MAXN];
ll ans=0;

pii dfs(int node, int prev, ll lcost){
    pii uwu={0,0};
    pii temp;
    if (val[node]==0) uwu.f++;
    if (val[node]==1) uwu.s++;
    for (int x:graph[node]){
        if (x==prev) continue;
        temp=dfs(x,node,min(cost[node],lcost));
        uwu.f+=temp.f; uwu.s+=temp.s;
    }
    if (cost[node]<=lcost){
        ll owo=min(uwu.f,uwu.s);
        ans+=cost[node]*owo*2;
        uwu.f-=owo; uwu.s-=owo;
    }
    return uwu;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b,c;i<=n;++i){
        cin >> a >> b >> c;
        cost[i]=a;
        val[i]=((b==c)?-1:b);
    }
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    pii temp;
    temp=dfs(1,1,0x3f3f3f3f);
    if (temp.f!=0||temp.s!=0) cout << -1 << '\n';
    else cout << ans << '\n';
}