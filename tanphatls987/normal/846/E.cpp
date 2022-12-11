#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N=1e5+10;
const ll inf=1e18;
int n;
ll a[N],need[N],w[N];
int pa[N];


ll mul(ll x,ll y){
    if (x>inf/y) return inf;
    return min(x*y,inf);
}
string solve(){
    for(int i=n;i>=1;i--){
        need[i]-=a[i];
        if (need[i]>=inf) return "NO";
        if (need[i]<=0){
            a[pa[i]]+=-need[i];
            continue;
        }
        if (i==1) return "NO";
        need[pa[i]]=min(inf,need[pa[i]]+mul(need[i],w[i]));
    }
    return "YES";
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>need[i];
    for(int i=2;i<=n;i++) cin>>pa[i]>>w[i];
    cout<<solve();
}