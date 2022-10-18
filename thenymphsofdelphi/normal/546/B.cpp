#include<bits/stdc++.h>
using namespace std;

bool ck[10000];

int main(){
    int n;
    cin >> n;
    int x, ans = 0;
    memset(ck, 0, sizeof(ck));
    for (int i = 0; i < n; i++){
        cin >> x;
        while (ck[x]){
            ans++;
            x++;
        }
        ck[x] = 1;
    }
    cout << ans;
}