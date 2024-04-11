#include <bits/stdc++.h>

using namespace std;

#define ll long long

int niz[2005];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> niz[i];
    sort(niz, niz+n);
    ll ans=0;
    for(int i=n-1; i>=0; i-=k){
        ans+=(niz[i]-1)*2;
    }
    cout << ans;
    return 0;
}