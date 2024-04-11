#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int a[N], b[N];

signed main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    if (a[x - 1] < b[m - y]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}