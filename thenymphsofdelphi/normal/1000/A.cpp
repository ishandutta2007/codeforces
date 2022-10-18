#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, c = 0;
    cin >> n;
    vector <string> a, b;
    string t;
    for (int i = 0; i < n; i++){
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++){
        cin >> t;
        b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b.size(); j++){
            if (a[i] == b[j]){
                a.erase(a.begin() + i);
                b.erase(b.begin() + j);
                i--;
                j--;
            }
        }
    }
    cout << a.size();
}