#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 0, b = 0, c = 0, n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (i % 3 == 0) a += x;
        else if (i % 3 == 1) b += x;
        else c += x;
    }
    if (a > b && a > c){
        cout << "chest";
    }
    else if (b > a && b > c){
        cout << "biceps";
    }
    else{
        cout << "back";
    }
}