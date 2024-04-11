#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int d; cin >> d;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int move = 0;
        for(int i=1;i<n;i++){
            while(move<d){
                if(a[i]>0 && move+i<=d){
                    --a[i];
                    ++a[0];
                    move+=i;
                }
                else{
                    break;
                }
            }
        }
        cout << a[0] << endl;
    }
}