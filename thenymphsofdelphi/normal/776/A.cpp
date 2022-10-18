#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c, d;
    int n;
    cin >> a >> b >> n;
    cout << a << ' ' << b << endl;
    for (int i = 0; i < n; i++){
        cin >> c >> d;
        if (c == a){
            a = d;
        }
        else{
            b = d;
        }
        cout << a << ' ' << b << endl;
    }
}