#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], mn = 10000, idx;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (mn > a[i]){
            mn = a[i];
            idx = i;
        }
    }
    if (n == 1 || (n == 2 && a[0] == a[1])){
        cout << -1;
    }
    else{
        sort(a, a + n);
        cout << 1 << "\n";
        cout << idx + 1;
    }
}