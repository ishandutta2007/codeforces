#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define f first
#define s second
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<ll,ll> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n,m; cin >> n >> m;
        vector<pii> arr(m); vector<ll> uwu;
        for (int i=0;i<m;++i) cin >> arr[i].s >> arr[i].f, uwu.push_back(arr[i].s);
        sort(arr.begin(),arr.end()); sort(uwu.begin(),uwu.end());
        reverse(arr.begin(),arr.end()); reverse(uwu.begin(),uwu.end());
        int p=0; ll cnt=0,tot=0,ans=0;
        for (int i=0;i<m;++i){
            while (p!=m&&cnt<n){
                if (uwu[p]>arr[i].f) cnt++,tot+=uwu[p],p++;
                else break;
            }
            if (cnt==n) ans=max(ans,tot);
            else if (arr[i].f>=arr[i].s) ans=max(ans,tot+arr[i].s+(n-cnt-1)*arr[i].f);
            else  ans=max(ans,tot+(n-cnt)*arr[i].f);
        }
        cout << ans << '\n';
    }
}