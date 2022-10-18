#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a = 1, b = 2, c = 3;
    cin >> n;
    while (n--){
        cin >> x;
        if (x == c){
            cout << "No";
            return 0;
        }
        if (x == b){
            swap(a, c);
        }
        else{
            swap(b, c);
        }
    }
    cout << "YES";
}