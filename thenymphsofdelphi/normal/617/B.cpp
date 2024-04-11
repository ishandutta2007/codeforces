#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, prev = -1, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        if (v == 1){
            if (prev == -1){
                ans = 1;
            }
            else{
                ans *= i - prev;
            }
            prev = i;
        }
    }
    cout << ans;
}