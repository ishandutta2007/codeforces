#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int u, v;
        cin >> u >> v;
        if (u==v){
            cout << 0 << endl;
            continue;
        }
        if (u<v){
            if ((u-v)&1){
                cout << 1 << endl;
                continue;
            }
            else{
                cout << 2 << endl;
                continue;
            }
        }
        if ((u-v)&1){
            cout << 2 << endl;
            continue;
        }
        cout << 1 << endl;
    }
    return 0;
}