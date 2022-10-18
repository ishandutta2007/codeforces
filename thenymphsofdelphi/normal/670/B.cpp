#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 1;
    while (k > cnt){
        k -= cnt;
        cnt++;
    }
    k--;
    cout << a[k];
}