#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while (t--){
        bool ck = false;
        cin >> n;
        while (n >= 0){
            if (n % 3 == 0){
                cout << "YES";
                ck = true;
                break;
            }
            n -= 7;
        }
        if (!ck){
            cout << "NO";
        }
        cout << endl;
    }
}