#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 0;
    a[n + 1] = 0;
    vector <int> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ck = 0, t = 0;
    for (int i = 1; i <= n + 1; i++){
        if (a[i]){
            ck = 1;
            t++;
        }
        else{
            if (ck){
                b.push_back(t);
                t = 0;
                ck = 0;
            }
        }
    }
    int ans = b.size();
    if (ans == 0){
        cout << 0;
        return 0;
    }
    for (int i = 0; i < b.size(); i++){
        ans += b[i];
    }
    ans--;
    cout << ans;
}