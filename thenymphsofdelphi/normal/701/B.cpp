#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int n, m;
    cin >> n >> m;
    bool a[n], b[n];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int x, y, cnta = n, cntb = n;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        x--;
        y--;
        if (!a[x]){
            cnta--;
            a[x] = 1;
        }
        if (!b[y]){
            cntb--;
            b[y] = 1;
        }
        cout << cnta * cntb << ' ';
    }
}