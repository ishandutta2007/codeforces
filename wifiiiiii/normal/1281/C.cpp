#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll ans = s.size();
        for(int i=0;i<n;++i) {
            int p = s[i]-'0'-1;
            ans += 1ll * (ans-i-1) * p;
            ans %= mod;
            if(s.size() > n) continue;
            string tmp = s.substr(i+1);
            while(p--)
            {
                s += tmp;
                if(s.size() > n) break;
            }
        }
        if(ans < 0) ans += mod;
        cout << ans << endl;
    }
}