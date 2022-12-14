#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s='1'+s;
    vector<int>ans(n+1,1),d(n+1,0),k(n+1,0);
    for(int i=1;i<=n;i++){
        d[i]=d[i-1];
        k[i]=k[i-1];
        if(s[i]=='D')d[i]++;
        else k[i]++;
    }
    for(int i=1;i<=n;i++){
        map<pair<int,int>,int>mp;
        for(int j=i;j<=n;j+=i){
            int a=d[j],b=k[j],gc=__gcd(a,b);
            a/=gc,b/=gc;
            mp[{a,b}]++;
            ans[j]=max(ans[j],mp[{a,b}]);
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
}