#include<bits/stdc++.h>
using namespace std;

#define int long long

int x, y, z, ans;
int n;
vector <int> a, b, c;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> x >> y >> z;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int t;
        string s;
        cin >> t >> s;
        if (s == "USB") a.push_back(t);
        else b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < min((int)a.size(), x); i++) ans += a[i];
    for (int i = 0; i < min((int)b.size(), y); i++) ans += b[i];
    for (int i = x; i < a.size(); i++) c.push_back(a[i]);
    for (int i = y; i < b.size(); i++) c.push_back(b[i]);
    sort(c.begin(), c.end());
    for (int i = 0; i < min((int)c.size(), z); i++) ans += c[i];
    cout << min((int)a.size(), x) + min((int)b.size(), y) + min((int)c.size(), z) << ' ' << ans;
}