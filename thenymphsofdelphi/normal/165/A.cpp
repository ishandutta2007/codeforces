#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        bool u = 0, d = 0, l = 0, r = 0;
        for (int j = 0; j < n; j++){
            if (i == j){
                continue;
            }
            if (a[i] == a[j]){
                if (b[i] < b[j]){
                    u = 1;
                }
                else{
                    d = 1;
                }
                continue;
            }
            if (b[i] == b[j]){
                if (a[i] < a[j]){
                    l = 1;
                }
                else{
                    r = 1;
                }
                continue;
            }
        }
        if (u && d && l && r){
            cnt++;
        }
    }
    cout << cnt;
}