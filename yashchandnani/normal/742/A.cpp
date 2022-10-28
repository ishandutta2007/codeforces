#include <bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    cin >> n;
    if(n==0) {
        cout<<1;
        return 0;
    }
    if(n%2==0){
        if(n%4==0) cout<< 6;
        else cout<<4;
    }
    else{
        if(n%4==1){
            cout<< 8;
        }
        else cout<< 2;
    }
    return 0;
}