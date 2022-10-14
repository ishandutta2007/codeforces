#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int inf=1e9;
int n,m,a[N],tmp;
vector<int> E[N];
bool was[N];
void DFS(int x){
    was[x]=1;tmp=min(tmp,a[x]);
    for(int c:E[x])if(!was[c])DFS(c);
}
int main(){
    scanf("%i %i",&n,&m);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=0,x,y;i<m;i++)scanf("%i %i",&x,&y),E[x].pb(y),E[y].pb(x);
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(!was[i])tmp=inf,DFS(i),ans+=tmp;
    }
    printf("%lld",ans);
    return 0;
}