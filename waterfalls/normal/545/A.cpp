#include <iostream>
#include <algorithm>

using namespace std;

int num[101][101];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin >> num[i][j];
    int good = 0;
    for (int i=0;i<n;i++) {
        int ok = 1;
        for (int j=0;j<n;j++) if (num[i][j]==1 || num[i][j]==3) ok = 0;
        good+=ok;
    }
    cout << good << endl;
    for (int i=0;i<n;i++) {
        int ok = 1;
        for (int j=0;j<n;j++) if (num[i][j]==1 || num[i][j]==3) ok = 0;
        if (ok) cout << (i+1) << " ";
    }

    return 0;
}