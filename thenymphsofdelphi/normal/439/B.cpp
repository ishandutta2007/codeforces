#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], n, l, sum = 0;

signed main(){
    cin >> n >> l;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        sum += a[i] * l;
        if (l != 1){
            l--;
        }
    }
    cout << sum;
}