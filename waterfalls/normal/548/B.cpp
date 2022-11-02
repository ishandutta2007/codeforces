#include <iostream>
#include <algorithm>

using namespace std;

int n,m,q;
int grid[500][500];
int ans[500];

void calc(int r) {
    int cur = 0;
    ans[r] = 0;
    for (int i=0;i<m;i++) {
        if (grid[r][i]) cur+=1;
        else ans[r] = max(ans[r],cur), cur = 0;
    }
    ans[r] = max(ans[r],cur);
}

int main() {
    cin >> n >> m >> q;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> grid[i][j];
    for (int i=0;i<n;i++) calc(i);
    for (int Q=0;Q<q;Q++) {
        int i,j;
        cin >> i >> j;
        i-=1; j-=1;
        grid[i][j]^=1;
        calc(i);
        int res = 0;
        for (int r=0;r<n;r++) res = max(res,ans[r]);
        cout << res << endl;
    }

    return 0;
}