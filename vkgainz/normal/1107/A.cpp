#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int q; cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n==1){
            cout << "NO" << endl;
        }
        else if(n==2){
            if(s.substr(0,1)<s.substr(1,1)){
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << s.substr(0,1) << " " << s.substr(1,1) << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "YES" << endl;
            cout << 2 << endl;
            string a =s.substr(0,1);
            string b = s.substr(1,n-1);
            cout << a << " " << b << endl;
        }
    }
}