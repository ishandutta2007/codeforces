#include<bits/stdc++.h>
using namespace std;

int a[100005], b[100005];

int main(){
    int n, l = 0, r = 0, mx = -1, bt, lt, rt;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        l += a[i];
        r += b[i];
    }
    bt = abs(l - r);
    for (int i = 0; i < n; i++){
        lt = l - a[i] + b[i];
        rt = r - b[i] + a[i];
        if (bt < abs(lt - rt)){
            mx = i;
            bt = abs(lt - rt);
        }
    }
    cout << mx + 1;
}