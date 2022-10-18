#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a, b, c;
    map <long double, int> cnt;
    map <long double, int>::iterator itr;
    cin >> n;
    long double arr[n];
    cin.ignore();
    for (int i = 0; i < n; i++){
        cin.ignore();
        cin >> a;
        cin.ignore();
        cin >> b;
        cin.ignore(2);
        cin >> c;
        cin.ignore();
        arr[i] = (1.0 * (a + b)) / (c * 1.0);
        itr = cnt.find(arr[i]);
        if (itr == cnt.end()){
            cnt[arr[i]] = 1;
        }
        else{
            cnt[arr[i]]++;
        }
    }
    for (int i = 0; i < n; i++){
        cout << cnt[arr[i]] << ' ';
    }
}