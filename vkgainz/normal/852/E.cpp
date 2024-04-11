#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
int inDegree[100001];

int main() {
    int n; cin >> n;
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin >> a >> b;
        --a, --b;
        ++inDegree[a], ++inDegree[b];
    }
    int l = 0;
    for(int i=0;i<n;i++) l+=(inDegree[i]==1);
    long long x = 1;
    for(int i=1;i<=n-l;i++) {
        x*=2;
        x%=mod;
    }
    long long ans = l*1LL*x*2%mod+(n-l)*1LL*x%mod;
    ans%=mod; if(ans<0) ans+=mod;
    cout << ans << endl;

}