#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        if(n % 2 == 1) {
            for(int i = 1; i < n - 3; i += 2) {
                swap(a[i], a[i-1]);
            }
            swap(a[n-3], a[n-2]);
            swap(a[n-3], a[n-1]);
        } else {
            for(int i = 1; i < n; i += 2) {
                swap(a[i], a[i-1]);
            }
        }
        for(int i : a) cout << i << " "; cout << endl;
    }
}