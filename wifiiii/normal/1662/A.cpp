#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<int> mx(10, -1);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int b, d;
            cin >> b >> d;
            --d;
            mx[d] = max(mx[d], b);
        }
        int more = 0, sum = 0;
        for(int i = 0; i < 10; ++i) {
            if(mx[i] == -1) more = 1;
            sum += mx[i];
        }
        if(more) cout << "MOREPROBLEMS\n";
        else cout << sum << '\n';
    }
}