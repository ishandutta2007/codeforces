#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--){
        long long p, f;
        cin >> p >> f;
        long long cnts, cntw;
        cin >> cnts >> cntw;
        long long s, w;
        cin >> s >> w;
        if (s > w || (s == w && cnts > cntw)){
            swap(s, w);
            swap(cnts, cntw);
        }
        if (p / s + f / s < cnts){
            cout << p / s + f / s << endl;
            continue;
        }
        long long ans = 0;
        for (long long i = 0; i <= min(cnts, p / s); i++){
            if (f - s * (cnts - i) < 0) continue;
            ans = max(ans, cnts + min(cntw, (p - s * i) / w + (f - s * (cnts - i)) / w));
        }
        cout << ans << endl;
    }
}