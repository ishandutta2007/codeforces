#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> a;
    string s;
    int n, t = 0, sz = 0;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++){
        if (s[i] == 'B'){
            t++;
        }
        else{
            if (t != 0){
                a.push_back(t);
                sz++;
                t = 0;
            }
        }
    }
    if (t != 0){
        a.push_back(t);
        sz++;
        t = 0;
    }
    cout << sz << '\n';
    for (int i = 0; i < sz; i++){
        cout << a[i] << " ";
    }
}