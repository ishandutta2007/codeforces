#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>> b;
        for(int i=0;i<=45000;i++){
            int x = min(a,b)-max(a,b)+i*(i+1)/2;
            if(x>=0 && x%2==0){
                cout << i << endl;
                break;
            }
        }
    }
}