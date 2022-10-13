#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string ret = "";
        int num8 = (n+3)/4;
        for(int i=0;i<num8;i++){
            ret+="8";
        }
        for(int i=0;i<n-num8;i++){
            ret = "9"+ret;
        }
        cout << ret << endl;
    }
}