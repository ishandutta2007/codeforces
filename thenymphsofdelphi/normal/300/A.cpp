#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, t;
    cin >> n;
    vector <int> a, b, c;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x < 0){
            a.push_back(x);
        }
        if (x > 0){
            b.push_back(x);
        }
        if (x == 0){
            c.push_back(x);
        }
    }
    if (a.size() % 2 == 0){
        t = a[a.size() - 1];
        a.pop_back();
        c.push_back(t);
    }
    if (b.size() == 0){
        t = a[a.size() - 1];
        a.pop_back();
        b.push_back(t);
        t = a[a.size() - 1];
        a.pop_back();
        b.push_back(t);
    }
    cout << a.size() << " ";
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << b.size() << " ";
    for (int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
    cout << c.size() << " ";
    for (int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
    cout << endl;
}