#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 5e5 + 10;
 
int n, m, k;
int n1;
int a[N];
int psum[N];
int coor[N];
int main() {
    cin >> n >> m;
 
    for(int i = 1; i <= n; i++) cin >> a[i];
 
    for(int i = 1; i <= n; i++) coor[i] = a[i];
    sort(coor + 1, coor + n + 1);
    n1 = unique(coor + 1, coor + n + 1) - coor - 1;
 
    k = min(1 << min(30, (m * 8) / n), n1);
 
    for(int i = 1; i <= n; i++) a[i] = 
        lower_bound(coor + 1, coor + n1 + 1, a[i]) - coor;
 
    for(int i = 1; i <= n; i++) psum[a[i]]++;
    for(int i = 1; i <= n1; i++) psum[i] += psum[i - 1];
 
    int ans = n + 1;
    for(int i = k; i <= n1; i++) {
        ans = min(ans, psum[i - k] + psum[n1] - psum[i]);
    }
    cout << ans;
}