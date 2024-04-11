#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve(){
    string in;
    cin >> in;
    int n = in.size();
    bool monotonic = true;
    for(char c : in){
        if(in[0] != c){
            monotonic = false;
            break;
        }
    }
    if(monotonic){
        cout << in << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << "01";
        }
        cout << endl;
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}