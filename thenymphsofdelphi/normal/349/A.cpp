#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 0, b = 0, c = 0, n, x;
    cin >> n;
    while (n--){
        cin >> x;
        if (x == 25){
            a++;
        }
        else if (x == 50){
            if (a == 0){
                cout << "NO";
                return 0;
            }
            a--;
            b++;
        }
        else if (x == 100){
            if (b >= 1 && a >= 1){
                b--;
                a--;
            }
            else if (a >= 3){
                a -= 3;
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}