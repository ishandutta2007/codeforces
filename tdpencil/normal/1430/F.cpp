#include <bits/stdc++.h>

using namespace std;
const int c=2002;
long long n, k, s, l[c], r[c], t[c], p[c], o=0, ans, pr;
int main() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> l[i] >> r[i] >> t[i], ans+=t[i];
    for (int i=n; i>=1; i--) {
        s=t[i];
        if (r[i]==l[i+1]) s+=p[i+1];
        p[i]=max(o, s-(r[i]-l[i])*k);
        if (p[i]>k) {cout << -1; return 0;}
    }
    s=k;
    for (int i=1; i<=n; i++) {
        if (s<p[i]) ans+=s, s=k;
        s=(s-t[i]%k+k)%k;
    }
    cout << ans;
}