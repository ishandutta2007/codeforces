#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x;
    bool ck[n];
    memset(ck, 1, sizeof(ck));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> x;
            if (x == 1) ck[i] = 0;
            if (x == 3){
                ck[i] = 0;
                ck[j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (ck[i]) ans++;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++){
        if (ck[i]) cout << i + 1 << " ";
    }
}