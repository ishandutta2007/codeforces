#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

signed main(){
    int n, d, mx = -1;
    cin >> n >> d;
    vector <pair <int, int> > a(n);
    int b[n];
    b[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++){
        b[i] = b[i - 1] + a[i - 1].se;
    }
    vector <pair <int, int> >::iterator itr;
    for (int i = 0; i < n; i++){
        itr = upper_bound(a.begin(), a.end(), make_pair(a[i].fi + d, -1LL));
        int idx = itr - a.begin();
        //cout << idx << ' ';
        mx = max(mx, b[idx] - b[i]);
    }
    cout << mx;
}