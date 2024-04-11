#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int n;
    cin >> n;
    cin >> a;
    int i;
    for (i = 1; i < a.length(); i++){
        if (a[i] != a[i - 1]){
            a.erase(i - 1, 2);
            a.insert(i - 1, "D");
        }
    }
    cout << a.length();
}