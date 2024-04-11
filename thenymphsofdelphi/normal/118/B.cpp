#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool ck;
    cin >> n;
    for (int i = 0; i < 2 * n + 1; i++){
        ck = true;
        for (int j = 0; j < 2 * n + 1; j++){
            if (abs(i - n) + abs(j - n) <= n){
                cout << n - abs(i - n) - abs(j - n);
                if (i == 0 || i == 2 * n){
                    break;
                }
                if (n - abs(i - n) - abs(j - n) == 0){
                    if (ck){
                        ck = false;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                cout << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }
}