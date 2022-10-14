#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n * 2);
    for(int i = 0; i < n * 2; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    cout << a[n].first + a[n - 1].first << " " << a[n].second + a[n - 1].second;
}