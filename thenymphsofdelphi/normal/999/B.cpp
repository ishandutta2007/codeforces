#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string a;
    cin >> n;
    cin >> a;
    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            reverse(a.begin(), a.begin() + i);
        }
    }
    cout << a;
}