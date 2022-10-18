#include<iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 1; i < n; i++){
        cin >> a[i];
    }
    int temp = 1;
    while (temp < x){
        temp += a[temp];
    }
    if (temp == x){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}