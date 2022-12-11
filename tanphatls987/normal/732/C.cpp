#include <bits/stdc++.h>

typedef long long ll;

const ll inf=4e18;

using namespace std;

ll a[3],ta[3];
ll solve(int st,int en){
    ll ans=0;
    for(int i=0;i<3;i++) ta[i]=a[i];
    for(int i=st;i<3;i++){
        if (!ta[i]) ans++;
        else ta[i]--;
    }
    for(int i=0;i<=en;i++){
        if (!ta[i]) ans++;
        else ta[i]--;
    }
    ll val=*max_element(ta,ta+3);
    for(int i=0;i<3;i++) ans+=val-ta[i];
//    cout<<st<<" "<<en<<" "<<ans<<'\n';
    return ans;
}
int main(){
    cin>>a[0]>>a[1]>>a[2];
    ll ans=inf;
    if (*max_element(a,a+3)<=1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++) ans=min(ans,solve(i,j));
    cout<<ans;
}