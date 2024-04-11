#include<bits/stdc++.h>
using namespace std;

int main(){
    string num;
    cin >> num;
    int len = num.length();
    if (num[0] != '-'){
        cout << num;
        return 0;
    }
    if (num[len - 1] > num[len - 2]){
        num.pop_back();
    }
    else{
        num.erase(len - 2, 1);
    }
    if (num == "-0"){
        cout << "0";
        return 0;
    }
    cout << num;
}