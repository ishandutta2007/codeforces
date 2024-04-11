#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<int> a(3);
        for(int i = 0; i < 3; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        if(a[2] == a[0] + a[1] || (a[0] == a[1] && a[2] % 2 == 0) || (a[0] % 2 == 0 && a[1] == a[2])) cout << "Yes\n";
        else cout << "No\n";
    }
}