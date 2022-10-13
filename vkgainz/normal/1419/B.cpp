#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        int p = 1;
        ll currsum = 0;
        while(p<=30 && currsum<=x){
            currsum+=(pow(2,p)-1)*1LL*pow(2,p-1);
            if(currsum>x)
                break;
            else{
                ++p;
            }
        }
        --p;
        cout << p << endl;
    }
}