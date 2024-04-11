#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n % 2 == 0) {
            for(int i = 0; i < n; i += 2)
                cout << i + 2 << " " << i + 1 << "\n";
        }
        else {
            cout << 3 << " " << 1 << " " << 2 << " ";
            for(int i = 3; i < n; i += 2)
                cout << i + 2 << " " << i + 1 << "\n";
        }
    }
}