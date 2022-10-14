#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> v;
        v.push_back(a[0]);
        int state = 0;
        if (a[0] < a[1]) state = 1;
        for (int i = 1; i < n; i++) {
            int new_state = 0;
            if (a[i] > a[i - 1]) new_state = 1;
            if (state == new_state) continue;
            else v.push_back(a[i - 1]);
            state = new_state;
        }
        v.push_back(a[n - 1]);
        cout << v.size() << '\n';
        for (auto c : v) cout << c << " ";
        cout << '\n';
    }
    return 0;
}