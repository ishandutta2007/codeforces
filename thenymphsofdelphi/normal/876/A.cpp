#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c, i = 0;
    cin >> n >> a >> b >> c;
    n--;
    int ans = 0, dis;
    while (n > 0){
        if (i == 0){
            dis = min(a, b);
            ans += dis;
            if (a == dis){
                i = 1;
            }
            else{
                i = 2;
            }
        }
        else if (i == 1){
            dis = min(a, c);
            ans += dis;
            if (a == dis){
                i = 0;
            }
            else{
                i = 2;
            }
        }
        else if (i == 2){
            dis = min(b, c);
            ans += dis;
            if (b == dis){
                i = 0;
            }
            else{
                i = 1;
            }
        }
        n--;
    }
    cout << ans;
}