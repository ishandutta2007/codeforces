#include<bits/stdc++.h>
using namespace std;

int a[400001], n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    int ans = 0, tmp = 0;
    for(int i = 1; i <= 2 * n; i++){
        if(a[i] == 1) tmp++;
        else{
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    cout << ans;
}