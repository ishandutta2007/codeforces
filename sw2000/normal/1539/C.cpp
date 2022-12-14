#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<ll>vi;
const int N=2e5+10,M=26;
const int mod=1e7+7;
 
ll arr[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    ll n,k,x;cin>>n>>k>>x;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    vi v;
    for(int i=2;i<=n;i++){
        if(arr[i]-arr[i-1]>x){
            v.push_back((arr[i]-arr[i-1]-1)/x);
        }
    }
    int ans=v.size()+1;
    sort(v.begin(),v.end());
    for(auto i:v){
        if(k>=i){
            k-=i;
            ans--;
        }
    }
    cout<<ans;
}