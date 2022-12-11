#include <bits/stdc++.h>

using namespace std;

map<int, int> ma; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= k + 1; i++) {
        cout << "? "; 
        for(int j = 1; j <= k + 1; j++) if (j != i)
            cout << j << " ";
        cout << endl;

        int pos, val;
        cin >> pos >> val;
        ma[val]++;
    }
    assert(ma.size() == 2);
    cout << "! " << ma.rbegin()->second;
}