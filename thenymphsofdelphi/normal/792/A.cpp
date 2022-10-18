#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[200005];

signed main(){
    int n, mn = 2000000005, dis, cnt;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++){
        dis = abs(a[i] - a[i - 1]);
        if (dis == mn){
            cnt++;
        }
        else if (dis < mn){
            cnt = 1;
            mn = dis;
        }
    }
    cout << mn << " " << cnt;
}