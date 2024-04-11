#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n; cin >> n;
    if(n==1){
        cout << -1 << endl;
    }
    else{
        string s = "2";
        for(int i=0;i<n-1;i++)
            s+="3";
        cout << s << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}