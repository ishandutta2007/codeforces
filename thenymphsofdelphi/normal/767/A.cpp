#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    int fl = n + 1;
    bool ck[n + 1];
    memset(ck, 0, sizeof(ck));
    while (n--){
        cin >> x;
        ck[x] = 1;
        if (fl - x == 1){
            while (ck[x]){
                cout << x << " ";
                fl--;
                x--;
            }
        }
        if (n != 0){
            cout << "\n";
        }
    }
}