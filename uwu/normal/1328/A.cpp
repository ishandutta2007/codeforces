#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t; cin >> t;
    for (int q=0;q<t;++q){
        ll a,b; cin >> a >> b;
        if (a%b==0) cout << 0 << '\n';
        else{
            cout << b-(a%b) << '\n';
        }
    }
    
}