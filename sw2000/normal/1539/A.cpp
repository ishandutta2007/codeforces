#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=100+10,M=26;
const int mod=1e7+7;
 
ll solve(){
    ll n,x,t;
    cin>>n>>x>>t;
    t/=x;
    t=min(n-1,t);
    return t*(t+1)/2+t*(n-t-1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<'\n';
    }
}