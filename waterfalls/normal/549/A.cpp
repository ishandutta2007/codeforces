#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string grid[53];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> grid[i];
    int ans = 0;
    for (int i=0;i<n-1;i++) for (int j=0;j<m-1;j++) {
        string cur;
        cur+=grid[i][j];
        cur+=grid[i+1][j];
        cur+=grid[i][j+1];
        cur+=grid[i+1][j+1];
        sort(cur.begin(),cur.end());
        if (cur=="acef") ans+=1;
    }
    cout << ans;

    return 0;
}