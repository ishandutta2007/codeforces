#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < (n+1)/2; i++){
        cin >> v[i];
    }
    int x;
    cin >> x;
    for(int i = (n+1)/2; i < n; i++){
        v[i] = x;
    }
    if(x > 0){
        ll total = 0;
        for(int i : v){
            total += i;
        }
        if(total > 0){
            cout << n << endl;
        }else{
            cout << "-1" << endl;
        }
    }
    else{
        int left = n-1;
        int right = n;
        ll suffix = v[n-1];
        ll total = v[n-1];
        bool reduce_right;
        if(total <= 0){
            total = suffix;
            right = n;
            reduce_right = false;
        }
        else{
            reduce_right = true;
        }
        while(left > 0){
            left -= 1;
            total += v[left];
            if(reduce_right){
                right -= 1;
                total -= v[right];
            }
            suffix += v[left];
            if(total <= 0){
                total = suffix;
                right = n;
                reduce_right = false;
            }
            else{
                reduce_right = true;
            }
        }
        if(total <= 0){
            cout << "-1" << endl;
        }else{
            cout << right - left << endl;
        }
    }
}

int main(){
    solve();
    return 0;
}