#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin >> k;
    if(k==0){
        cout << 1 << " " << 1 << endl;
        cout << 1 << endl;
    }
    else{
        cout << 3 << " " << 4 << endl;
        int x = 262143; int y=  131071;
        cout << x << " " << y << " " << " " <<  y <<  " " << 0 << endl;
        cout << (y+1) << " " << (y+1) << " " << y << " " << 0 << endl;
        cout <<x << " " << x << " " << x << " " << k << endl;
    }
}