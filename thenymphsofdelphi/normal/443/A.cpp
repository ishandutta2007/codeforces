#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string a;
    int n, i, cnt = 1;
    getline(cin, a);
    n = a.length();
    for (i = 0; i < n; i++){
        if (a[i] == '{' || a[i] == '}' || a[i] == ',' || a[i] == ' '){
            a.erase(i, 1);
            i--;
            n--;
        }
    }
    sort(a.begin(), a.end());
    if (a == ""){
        cout << "0";
        return 0;
    }
    for (i = 1; i < n; i++){
        if (a[i] != a[i - 1]){
            cnt++;
        }
    }
    cout << cnt;
}