#include<bits/stdc++.h>
#define lo (o<<1)
#define ro (o<<1|1)
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 400 + 10;

int n,mod;
//two[410]{1,1},f[410],cnt[410];
ll f[410][410],C[410][410]{1};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n>>mod;
    for(int i=1;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    f[1][1]=1;
    for(int i=2;i<=n;i++){
        f[i][i]=f[i-1][i-1]*2%mod;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<i;j++){
            for(int k=1;k<j;k++){
                f[i][j]+=f[k][k]*f[i-k-1][j-k]%mod*C[j][k]%mod;
                f[i][j]%=mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans=(ans+f[n][i])%mod;
    cout<<ans;
	return 0;
}