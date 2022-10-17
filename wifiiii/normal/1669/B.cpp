#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ok = -1;
        map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(++mp[x] == 3) {
                ok = x;
            }
        }
        cout << ok << '\n';
    }
}