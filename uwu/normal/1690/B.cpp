#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n+1);
        vector<int>b(n+1);
        bool f = true;
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        for(int i = 1; i<=n; i++){
            cin >> b[i];
            if(b[i]>a[i]){
                f = false;
            }
        }
        if(!f){
            cout << "NO\n";
            continue;
        }
        int mx = 0;
        vector<int>c(n+1);
        for(int i = 1; i<=n; i++){
            mx = max(mx,a[i]-b[i]);
        }
        for(int i = 1; i<=n; i++){
            c[i] = a[i]-mx;
            c[i] = max(c[i],0LL);
            if(c[i]!=b[i])f = false;
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}