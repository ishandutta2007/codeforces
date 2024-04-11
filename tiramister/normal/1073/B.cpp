#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int pa[n];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        pa[a] = i;
    }

    int itr = -1;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        --b;
        cout << max(0, pa[b] - itr) << " ";
        itr = max(itr, pa[b]);
    }
    cout << endl;
    return 0;
}