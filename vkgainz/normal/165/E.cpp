#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    vector<int> sto(1 << 22, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sto[a[i]] = a[i];
    }

    for(int i = 0; i < 22; i++) {
        for(int j = 0; j < (1 << 22); j++) {
            if(j & (1 << i))
                if(sto[j ^ (1 << i)] != -1)
                    sto[j] = sto[j ^ (1 << i)];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << sto[(1 << 22) - 1 - a[i]] << " ";
    }
}