#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m, idx = 0;
    cin >> n >> m;
    int a[n + 1];
    vector <int> b;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[n] = 1e9;
    sort(a, a + n);
    int t = 1;
    while (m >= 0){
        if (t == a[idx]){
            idx++;
            t++;
            continue;
        }
        if (m < t){
            break;
        }
        m -= t;
        b.push_back(t);
        t++;
    }
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
}