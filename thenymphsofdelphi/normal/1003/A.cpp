#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], cnt[101];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mx = -1;
    for (int i = 1; i <= 100; i++){
        mx = max(mx, cnt[i]);
    }
    cout << mx;
}