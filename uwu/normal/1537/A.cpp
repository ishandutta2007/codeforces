#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=51;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n+1);
        ll tot=0;
        for (int i=1;i<=n;++i) cin >> a[i];
        for (int i=1;i<=n;++i) tot+=a[i];
        if (tot<n) tot=n+1;
        cout << tot-n << '\n';
    }
}