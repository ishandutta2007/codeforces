#include <iostream>
using namespace std;
int t, n;
void solve(){
    if(n%4==0){
        cout << "YES" << endl;

    }
    else{
        cout << "NO" << endl;

    }
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        solve();
    }
}