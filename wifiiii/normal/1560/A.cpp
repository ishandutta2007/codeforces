#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> ans {0};
    for(int i = 1; ; ++i) {
        if(i % 3 == 0 || i % 10 == 3) continue;
        ans.push_back(i);
        if(ans.size() > 1000) break;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}