#include<iostream>
using namespace std;

int main(){
    int n, ans;
    cin >> n;
    ans = n / 5;
    if (ans * 5 != n){
        ans++;
    }
    cout << ans;
}