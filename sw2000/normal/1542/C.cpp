#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1000+10;
const int mod=1e9+7;

int mul[N];
int solve(){
    ll n;cin>>n;
    ll ret=n%mod;
    for(ll base=1,i=2;base<=n;i++){
        ret=(ret+n/base)%mod;
        base*=mul[i];
    }
    return ret;
}
int main() {
    for(int i=2;i<N;i++)if(!mul[i]){
        for(int j=i*i;j<N;j+=i)mul[j]=1;
        for(int j=i;j<N;j*=i)mul[j]=i;
    }

//    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<'\n';
    }
}