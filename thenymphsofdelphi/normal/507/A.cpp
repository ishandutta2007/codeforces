#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    pair <int, int> a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    int cnt = 0, idx = 0;
    vector <int> x;
    do{
        cnt += a[idx].first;
        x.push_back(a[idx].second);
        idx++;
    } while (cnt <= k && idx <= n);
    x.pop_back();
    cnt -= a[idx - 1].first;
    cout << idx - 1 << "\n";
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
}