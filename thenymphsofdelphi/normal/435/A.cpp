#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 1, cur = 0;
    for(int i = 0; i < n; i++){
        if (cur + a[i] <= m){
            cur += a[i];
        }
        else{
            ans++;
            cur = a[i];
        }
    }
    cout << ans;
}