#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x,y; cin >> x >> y;
        if(x>=4) cout << "YES" << endl;
        else{
            if(x==1){
                if(y==1) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else{
                if(y<=3) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}