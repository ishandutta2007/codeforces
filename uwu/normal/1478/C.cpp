#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

ll arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n; n=n*2;
        for (int i=1;i<=n;++i) cin >> arr[i];
        sort(arr+1,arr+1+n);
        bool ans=arr[1]%2==0;
        ans&=arr[n]%n==0;
        ll cnt=n-2;
        ll last=arr[n]/n;
        for (int i=n;i>=2;i-=2){
            ans&=arr[i]==arr[i-1];
            if (cnt!=0){
                ans&=(arr[i]-arr[i-2])%cnt==0;
                if (arr[i]-arr[i-2]==0) ans=0;
                last-=(arr[i]-arr[i-2])/cnt;
                ans&=last>0;
            }
            cnt-=2;
        }
        cout << (ans?"YES":"NO") << '\n';
    }
}