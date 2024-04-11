#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        long long sum = 0LL;
        int mx = 0;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            sum+=a[i];
            mx = max(mx, a[i]);
        }
        cout << max(mx*1LL, (sum+n-2)*1LL/(n-1))*1LL*(n-1)-sum << "\n";
    }
}