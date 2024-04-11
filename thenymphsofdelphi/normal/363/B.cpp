#include<bits/stdc++.h>
using namespace std;

int a[500001];

int main(){
    int n, k, idx, mx = 100000000, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if (i >= k){
            sum -= a[i - k];
        }
        if (i >= k - 1){
            if (sum < mx){
                mx = sum;
                idx = i - k + 2;
            }
        }
    }
    cout << idx;
}