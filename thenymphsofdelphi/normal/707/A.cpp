#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    char x;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> x;
            if (x == 'C' || x == 'Y' || x == 'M'){
                cout << "#Color";
                return 0;
            }
        }
    }
    cout << "#Black&White";
}