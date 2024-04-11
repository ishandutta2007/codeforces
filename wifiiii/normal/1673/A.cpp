#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            if(i != 0) l += s[i] - 'a' + 1;
            if(i + 1 < n) r += s[i] - 'a' + 1;
            sum += s[i] - 'a' + 1;
        }
        int alice = n % 2 == 0 ? sum : max(l, r), bob = sum - alice;
        if(alice > bob) cout << "Alice " << alice - bob << '\n';
        else cout << "Bob " << bob - alice << '\n';
    }
}