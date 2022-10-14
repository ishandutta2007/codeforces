#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N=200050;

ll a[N],b[N];
vector<int> E[N],ord;
void DFS(int u){
    for(int v:E[u])DFS(v);
    if(u)ord.pb(u);
}

bool was[N];
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)E[max(0LL,b[i])].pb(i);
    DFS(0);
    ll ans=0;
    vector<int> order;
    for(int i:ord)if(a[i]>=0){
        ans+=a[i];
        if(b[i]>0)a[b[i]]+=a[i];
        was[i]=true;
        order.pb(i);
    }
    reverse(ord.begin(),ord.end());
    for(int i:ord)if(!was[i]){
        ans+=a[i];
        if(b[i]>0)a[b[i]]+=a[i];
        order.pb(i);
    }
    assert((int)order.size()==n);
    printf("%lld\n",ans);
    for(int i:order)printf("%i ",i);
    return 0;
}