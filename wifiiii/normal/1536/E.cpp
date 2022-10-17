#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int cnt=0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                char c;
                cin>>c;
                if(c=='#') ++cnt;
            }
        }
        ll ans=fpow(2,cnt)-(n*m==cnt);
        cout<<ans<<endl;
    }
}