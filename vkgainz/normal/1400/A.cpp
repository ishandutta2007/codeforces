#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string t;
        for(int i=0;i<n;i++){
            t+=s[2*i];
        }
        cout << t << endl;
        
    }
}