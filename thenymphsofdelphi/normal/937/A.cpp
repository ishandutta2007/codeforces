#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, cnt = 0;
    bool ck[601];
    memset(ck, 0, sizeof(ck));
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        ck[x] = 1;
    }
    for (int i = 1; i <= 600; i++){
        if (ck[i]){
            cnt++;
        }
    }
    cout << cnt;
}