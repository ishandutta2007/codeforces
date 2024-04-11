#include <bits/stdc++.h>
 
#define F first
#define S second
#define rsz resize
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using ld = double;
using pi = pair<int, int>;
using vpi = vector<pi>;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x = 0, t = 0, y = 0, ok = 1; cin >> n; vi a(n);
    for(int i = 0; i < n; x = max(x, a[i++])) cin >> a[i];
    for(int i = 0; i < n; ++i) {
        //if(a[i] < x) ok = ok && a[i] >= y, y = a[i];
        if(i && abs(a[i]-a[i-1]) > 1) ok = 0;
    }
    cout << (ok  ? "YES" : "NO") << endl;
}