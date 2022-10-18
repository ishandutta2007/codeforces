#include<bits/stdc++.h>
using namespace std;

int sumdig(int n){
    int ans = 0;
    while (n != 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main(){
    int n, t;
    cin >> n;
    vector <int> ans;
    for (int i = 1; i <= 100; i++){
        t = n - i;
        if (sumdig(t) == i){
            ans.push_back(t);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}