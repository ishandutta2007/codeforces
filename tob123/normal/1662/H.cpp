#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define LL long long
#define st first
#define nd second
#define endl '\n'
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        LL w, l;
        cin >> w >> l;
        set<int> ans;
        auto Test = [&](LL x, LL y) {
            LL z = __gcd(x, y);
            for(LL k = 1; k * k <= z; ++k) {
                if(z % k == 0) {
                    ans.insert(k);
                    ans.insert(z / k);
                }
            }
        };
        Test(w - 2, l);
        Test(w, l - 2);
        Test(w - 1, l - 1);
        if(w % 2 == 0 && (l - 1) % 2 == 0) {
            ans.insert(2);
        }
        if(l % 2 == 0 && (w - 1) % 2 == 0) {
            ans.insert(2);
        }
        cout << ans.size() << " ";
        for(auto it = ans.begin(); it != ans.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

}