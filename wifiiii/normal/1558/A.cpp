#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        vector<int> ans(a + b + 1);
        int n = a + b;
        for(int aw = 0; aw <= a; ++aw) {
            {
                int aa = n / 2, bb = n - aa;
                int al = aa - aw, bl = a - aw, bw = bb - bl;
                if(aw >= 0 && al >= 0 && bw >= 0 && bl >= 0) ans[al + bl] = 1;
            }
            {
                int bb = n / 2, aa = n - bb;
                int al = aa - aw, bl = a - aw, bw = bb - bl;
                if(aw >= 0 && al >= 0 && bw >= 0 && bl >= 0) ans[al + bl] = 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i <= a + b; ++i) if(ans[i]) ++cnt;
        cout << cnt << endl;
        for(int i = 0; i <= a + b; ++i) if(ans[i]) cout << i << " ";
        cout << endl;
    }
}