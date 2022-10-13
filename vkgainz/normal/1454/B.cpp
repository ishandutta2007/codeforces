#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int f[n+1];
        int idx[n+1];
        memset(f,0,sizeof(f));
        memset(idx,-1,sizeof(idx));
        for(int i=0;i<n;i++) {
            idx[a[i]] = i;
            ++f[a[i]];
        }
        int ret = 200000+5;
        for(int i=1;i<=n;i++) {
            if(f[i]==1){
                ret = idx[i];
                break;
            }
        }
        if(ret>n) cout << -1 << endl;
        else cout << ret+1 << "\n";
    }
}