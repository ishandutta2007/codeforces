#include<iostream>
using namespace std;

int main(){
    int t, a, b, c = 0;
    cin >> t;
    while (t--){
        cin >> a >> b;
        if ((b - a) >= 2) c++;
    }
    cout << c;
}