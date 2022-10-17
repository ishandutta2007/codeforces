#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(5));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 5; ++j) {
                cin >> a[i][j];
            }
        }
        int f = 0;
        for(int i1 = 0; i1 < 5; ++i1) {
            for(int i2 = i1 + 1; i2 < 5; ++i2) {
                int x = 0, y = 0, z = 0, ok = 1;
                for(int i = 0; i < n; ++i) {
                    if(!a[i][i1] && !a[i][i2]) {
                        ok = 0;
                        break;
                    } else if(a[i][i1] && a[i][i2]) {
                        z++;
                    } else if(a[i][i1]) {
                        x++;
                    } else {
                        y++;
                    }
                }
                if(!ok) continue;
                if(x + z >= n / 2 && y + z >= n / 2) f = 1;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
}