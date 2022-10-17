#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5001;

ll a[MAXN], b[MAXN];

void slow(int n){
    ll ans=0;
    set<int> s;
    for (int i=1;i<=n;++i) if (b[i]!=1) s.insert(i);
    while (!s.empty()){
        int curr=*s.begin();
        while (true){
            b[curr]--;
            if (b[curr]==1) s.erase(curr);
            auto it=s.lower_bound(curr+b[curr]+1);
            if (it==s.end()) break;
            curr=*it;
        }
        ans++;
    }
    cout << ans << " ";
}

void solve(){
    int n; cin >> n;
    ll ans=0;
    set<int> s;
    for (int i=1;i<=n;++i) cin >> a[i], b[i]=a[i];
    // slow(n);
    for (int i=1;i<=n;++i){
        if (a[i]!=1) s.insert(i);
    }
    while (!s.empty()){
        int curr=*s.begin();   
        if (a[curr]>6000){
            ans+=a[curr]-6000, a[curr]=6000;
        }
        while (true){
            auto it=s.lower_bound(curr+a[curr]);

            a[curr]--;
            if (a[curr]==1) s.erase(curr);
            if (it==s.end()) break;
            curr=*it;
        }
        ans++;
    }
    cout << ans << '\n';
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
}