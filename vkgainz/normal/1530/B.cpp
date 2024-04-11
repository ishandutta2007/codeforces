#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int h, w; cin >> h >> w;
        int ans[h][w];
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                ans[i][j] = 0;
        for(int j = 0; j < w; j += 2) {
            ans[0][j] = 1;
        }
        for(int i = 1; i < h; i++) {
            if(ans[i - 1][0] != 1 && ans[i - 1][1] != 1)
                ans[i][0] = 1;
            if(ans[i - 1][w - 1] != 1 && ans[i - 1][w - 2] != 1)
                ans[i][w - 1] = 1;
        }
        for(int j = 1; j < w - 1; j++) {
            if(ans[h - 2][j - 1] != 1 && ans[h - 2][j + 1] != 1) {
                if(ans[h - 1][j - 1] != 1 && ans[h - 1][j + 1] != 1)
                    ans[h - 1][j] = 1;
            }
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
}