#include<bits/stdc++.h>
using namespace std;

vector <int> a;

int main(){
    int sum = 0, n, m, p, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x < 0){
            a.push_back(-x);
        }
    }
    p = a.size();
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < min(m, p); i++){
        sum += a[i];
    }
    cout << sum;
}