#include <bits/stdc++.h>
using namespace std;

int ans[501][501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    if(N < 3) {
        cout << -1 << "\n";
        return 0;
    }
    if(N == 3) {
        ans[0][0] = 7, ans[0][1] = 2, ans[0][2] = 8;
        ans[1][0] = 9, ans[1][1] = 1, ans[1][2] = 3;
        ans[2][0] = 6, ans[2][1] = 5, ans[2][2] = 4;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    ans[0][0] = 4, ans[0][1] = 3, ans[0][2] = 6, ans[0][3] = 12;
    ans[1][0] = 7, ans[1][1] = 5, ans[1][2] = 9, ans[1][3] = 15;
    ans[2][0] = 14, ans[2][1] = 1, ans[2][2] = 11, ans[2][3] = 10;
    ans[3][0] = 13, ans[3][1] = 8, ans[3][2] = 16, ans[3][3] = 2;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            ans[i][j] += (N * N - 16);
        }
    }
    int x = 0;
    int i = 4, j = 0;
    bool down = true;
    while(true) {
        ans[i][j] = ++x;
        if(down) {
            ++i;
            if(i >= N) {
                if(j == N - 1) {
                    --i;
                    break;
                }
                --i, ++j, down = 1 - down;
            }
        }
        else {
            --i;
            if(i < 4) {
                if(j == N - 1) {
                    ++i;
                    break;
                }
                ++i, ++j, down = 1 - down;
            }
        }
    }
    i = 0;
    bool left = true;
    while(true) {
        if(ans[i][j] > 0) break;
        ans[i][j] = ++x;
        if(left) {
            --j;
            if(j < 4) {
                ++j, ++i;
                left = 1 - left;
            }
        }
        else {
            ++j;
            if(j >= N) {
                --j, ++i;
                left = 1 - left;
            }
        }
    }
    for(int j = 4; j < N; j++) {
        int x = ans[2][j];
        ans[2][j] = ans[3][j];
        ans[3][j] = x;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}