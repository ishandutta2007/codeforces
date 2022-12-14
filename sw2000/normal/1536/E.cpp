#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
const int mod=1e9+7;

int solve(){
    int n,m;cin>>n>>m;
    vector<string>boa(n);
    for(auto &i:boa)cin>>i;
    int ret=1,f=1;
    for(auto i:boa)for(auto j:i){
        if(j=='#')ret=ret*2%mod;
        else f=0;
    }
    return ret-f;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<'\n';
    }
}