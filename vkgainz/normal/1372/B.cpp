#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i = 0;
        for(int x=2;x<=sqrt(n)+1;x++){
            if(n%x==0){
                i = x;
                break;
            }
        }
        if(i==0){
            cout << 1 << " " << n-1 << endl;
        }
        else{
            
        cout << n/i << " " << n-n/i << endl;
        }
    }
}