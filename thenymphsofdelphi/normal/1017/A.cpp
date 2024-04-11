#include<bits/stdc++.h>
using namespace std;

bool cmp1(pair <int, int> a, pair <int, int> b){
    if (a.first < b.first){
        return 0;
    }
    if (a.first > b.first){
        return 1;
    }
    if (a.second > b.second){
        return 0;
    }
    return 1;
}

int main(){
    int n, x1, x2, x3, x4, sum;
    cin >> n;
    vector <pair <int, int> > a(n);
    for (int i = 1; i <= n; i++){
        cin >> x1 >> x2 >> x3 >> x4;
        sum = x1 + x2 + x3 + x4;
        a[i - 1] = make_pair(sum, i);
    }
    sort(a.begin(), a.end(), cmp1);
    for (int i = 0; i < n; i++){
        if (a[i].second == 1){
            cout << i + 1;
            return 0;
        }
    }
}