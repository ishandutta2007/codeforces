#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    a[n - 1] = 1;
    for(int i = 2; i <= n; ++i) {
        cout << "? ";
        for(int j = 1; j < n; ++j) cout << 1 << " ";
        cout << i << endl;
        int ret;
        cin >> ret;
        if(ret == 0) {
            a[n - 1] = n + 2 - i;
            break;
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(i == a[n - 1]) continue;
        cout << "? ";
        for(int j = 1; j < n; ++j) cout << n + 1 - i << " ";
        cout << n + 1 - a[n - 1] << endl;
        int ret;
        cin >> ret;
        assert(ret);
        a[ret - 1] = i;
    }
    cout << "! ";
    for(int i : a) cout << i << " ";
    cout << endl;
}