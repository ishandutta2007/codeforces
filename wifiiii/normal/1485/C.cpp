#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    // a / b = a - a % b * b = a % b
    // 1. a = (b + 1) * (a % b)
    // 2. if (b+1)|a, a % b = a / (b + 1) % b
    // a % (b+1) = 0 and a / (b+1) < b
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        ll ans = 0;
        for(int i=1;i<=b;++i) {
            if(a>=i*(i+1)) {
                ans+=i-1;
            } else {
                for(int j=i+1,nxt;j<=min(a,b+1);j=nxt+1) {
                    nxt=min(b+1,a/(a/j));
                    ans+=a/j*(nxt-j+1);
                }
                break;
            }
        }
        cout << ans << endl;
    }
}