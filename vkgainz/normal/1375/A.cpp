#include <bits/stdc++.h>
using namespace std;


int main(){
   int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            if(i%2==0){
                cout << -abs(a) << endl;
            }
            else{
                cout << abs(a) << endl;
            }
        }
    }
}