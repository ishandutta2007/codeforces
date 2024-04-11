
 #include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if (k == 0){
        for (int i = 1; i <= n; i++){
            cout << i << ' ';
        }
        return 0;
    }
    for (int i = n; i >= n - k + 1; i--){
        cout << i << ' ';
    }
    for (int i = 1; i <= n - k; i++){
        cout << i << ' ';
    }
}