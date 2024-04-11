#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;

void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    for(auto &i:arr)cin>>i;
    for(auto i:arr){
        if(i<0){cout<<"no\n";return;}
    }
    cout<<"yes\n";
    cout<<"101\n";
    for(int i=0;i<=100;i++)cout<<i<<' ';cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
}