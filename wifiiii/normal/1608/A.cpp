#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cout << int(1e8 + i) << " ";
        }
        cout << '\n';
    }
}