#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t, c, x, ans = 0;
    cin >> n >> t >> c;
    vector <int> a;
    a.push_back(-1);
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x > t){
            a.push_back(i);
        }
    }
    a.push_back(n);
    for (int i = 1; i < a.size(); i++){
        ans += max(0, a[i] - a[i - 1] - c);
    }
    cout << ans;
}