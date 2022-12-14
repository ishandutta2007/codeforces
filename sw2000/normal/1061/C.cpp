#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
const int mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int n;cin>>n;
    vi arr(n);
    for(auto &i:arr)cin>>i;
    vi dp(N,0);
    dp[0]=1;
    for(auto i:arr){
        vi v{1,i};
        for(int j=2;j*j<=i;j++)if(i%j==0){
            v.push_back(j);
            if(j*j!=i)v.push_back(i/j);
        }
        sort(v.begin(),v.end(),greater<int>());
        v.resize(unique(v.begin(),v.end())-v.begin());
        for(auto j:v)dp[j]=(dp[j-1]+dp[j])%mod;
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=(ans+dp[i])%mod;
    cout<<ans;
    return 0;
}