#include<bits/stdc++.h>
using namespace std;

int a[200001], pre[200001], n, pre2[200001], b;

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
        pre2[i + 1] = pre[i + 1];
    }
    sort(pre2 + 1, pre2 + n + 1);
    for(int i = 2; i <= n; i++){
        if(pre2[i] - pre2[i - 1] != 1){
            cout << -1;
            return 0;
        }
    }
    int b = -pre2[1] + 1;
    cout << b << " ";
    for(int i = 1; i < n; i++){
        b += a[i];
        cout << b << " ";
    }
}