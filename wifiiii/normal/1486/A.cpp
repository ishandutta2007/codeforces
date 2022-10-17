#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll ok = 1, sum = 0, cur = 0;
        for(int i=1;i<=n;++i) {
            int x;
            cin>>x;
            sum+=x;
            cur+=(i-1);
            if(sum<cur) ok=0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}