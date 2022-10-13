#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n<31){
            cout << "NO"<< endl;
        }
        else{
            cout << "YES" << endl;
            if(n!=36 && n!=44 && n!=40){
                cout << 6 << " " << 10 << " " << 14 << " " << (n-30) << endl;
            }
            else{
                cout << 6 << " " << 10 << " " << 15 << " " << (n-31) << endl;
            }
        }
    }
}