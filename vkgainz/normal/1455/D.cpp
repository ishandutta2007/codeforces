#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e6+5;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int ans = 0;
        for(int num=0;num<n;num++) {
            bool s = true;
            for(int i=1;i<n;i++)
                if(a[i-1]>a[i]) s = false;
            if(s) break;
            for(int i=0;i<n;i++) {
                if(a[i]<=x) continue;
                if(a[i]>x) {
                    int temp = x;
                    x = a[i];
                    a[i] = temp;
                    ++ans;
                }
                s = true;
                for(int i=1;i<n;i++)
                    if(a[i-1]>a[i]) s = false;
                if(s) break;
            }
        }
            bool s = true;
            for(int i=1;i<n;i++)
                if(a[i-1]>a[i]) s = false;
            if(s) cout << ans << "\n";
            else cout << -1 << "\n";
    }
}