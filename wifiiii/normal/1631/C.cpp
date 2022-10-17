#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> match(n, -1);
        for(int i = 0; i < n; ++i) match[i] = n - 1 - i;
        if(k < n - 1) {
            match[0] = match[k], match[match[k]] = 0;
            match[k] = n - 1, match[n - 1] = k;
            for(int i = 0; i < n; ++i) {
                if(i < match[i]) {
                    cout << i << ' ' << match[i] << endl;
                }
            }
        } else {
            if(n == 4) {
                cout << -1 << '\n';
            } else {
                match[0] = 2;
                match[2] = 0;
                match[1] = n - 3;
                match[n - 3] = 1;
                match[n - 1] = n - 2;
                match[n - 2] = n - 1;
                for(int i = 0; i < n; ++i) {
                    if(i < match[i]) {
                        cout << i << ' ' << match[i] << endl;
                    }
                }
            }
        }
    }
}