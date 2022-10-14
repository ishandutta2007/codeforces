#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=200050;
int n,a[N],cnt[N];
ll sum[N];
vector<int> E[N];
bool was[N];
void DFS(int u){
    was[u]=1,sum[u]=a[u];
    for(int c:E[u]){
        if(!was[c])DFS(c),sum[u]+=sum[c],cnt[u]+=cnt[c];
    }
    if(E[u].empty())cnt[u]=1;
}
int main(){
    scanf("%i",&n);
    for(int i=2;i<=n;i++){
        int p;scanf("%i",&p);
        if(p!=i)E[p].pb(i);
    }
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    DFS(1);
    ll ans=0;
    for(int i=1;i<=n;i++)if(cnt[i]>0)ans=max(ans,(sum[i]+cnt[i]-1)/cnt[i]);
    printf("%lld",ans);
    return 0;
}