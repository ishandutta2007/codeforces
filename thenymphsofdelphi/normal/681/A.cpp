#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s >> x >> y;
        if (x >= 2400 && y > x){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}