#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x; cin >> x;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int same = 0;
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum+=x-a[i];
            same+=(a[i]==x);
        }
        if(same==n){
            cout << 0 << endl;
        }
        else{
            if(sum==0 || same>=1) cout << 1 << endl;
            else{
                cout << 2 << endl;
            }
        }
    }
}