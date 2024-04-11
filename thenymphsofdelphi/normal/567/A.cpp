#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 10000000000;
int a[100002];

signed main(){
    a[0] = -INF;
    int n, difmnl, difmnr, difmxl, difmxr;
    cin >> n;
    a[n + 1] = INF;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        difmnl = abs(a[i] - a[i - 1]);
        difmnr = abs(a[i + 1] - a[i]);
        cout << min(difmnl, difmnr) << " ";
        difmxl = abs(a[i] - a[1]);
        difmxr = abs(a[n] - a[i]);
        cout << max(difmxl, difmxr) << endl;
        //cout << difmnl << " " << difmnr << " " << difmxl << " " << difmxr << endl;
    }
}