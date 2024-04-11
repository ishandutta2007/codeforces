#include<bits/stdc++.h>
using namespace std;

vector <long long> a;

int main(){
    int n, m, dor, room;
    cin >> n >> m;
    a.push_back(0);
    long long x, ind;
    for (int i = 0; i < n; i++){
        cin >> x;
        a.push_back(a[i] + x);
    }
    while (m--){
        cin >> ind;
        dor = lower_bound(a.begin(), a.end(), ind) - a.begin();
        cout << dor << " " << ind - a[dor-1] << endl;
    }
}