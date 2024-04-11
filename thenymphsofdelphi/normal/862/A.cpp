#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, cnt[101];
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < x; i++){
        if (cnt[i] == 0){
            ans++;
        }
    }
    if (cnt[x]){
        ans += cnt[x];
    }
    cout << ans;
}