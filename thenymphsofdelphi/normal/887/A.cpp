#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin >> a;
    int cnt0 = 0;
    bool ck = 0;
    for (int i = 0; i < a.length(); i++){
        if (a[i] == '1'){
            ck = 1;
        }
        if (a[i] == '0' && ck){
            cnt0++;
        }
    }
    if (cnt0 >= 6){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}