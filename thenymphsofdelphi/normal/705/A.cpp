#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int n, i;
    string a = "I hate it", b = "I love it", c = "I hate that", d = "I love that";
    string ans = "";
    bool ck = true;
    cin >> n;
    for (i = 0; i < n; i++){
        if (ck){
            if (i == n - 1){
                ans += a + " ";
                cout << ans;
                return 0;
            }
            ans += c + " ";
            ck = false;
        }
        else{
            if (i == n - 1){
                ans += b + " ";
                cout << ans;
                return 0;
            }
            ans += d + " ";
            ck = true;
        }
    }
}