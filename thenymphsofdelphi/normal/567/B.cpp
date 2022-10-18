#include<bits/stdc++.h>
using namespace std;

bool ck[1000005];

int main(){
    int q, n, ans = 0, t = 0;
    char c;
    cin >> q;
    while (q--){
        cin >> c >> n;
        if (c == '+'){
            ck[n] = 1;
            t++;
            if (t > ans){
                ans = t;
            }
        }
        else{
            if (ck[n]){
                ck[n] = 0;
                t--;
            }
            else{
                ans++;
            }
        }
    }
    cout << ans;
}