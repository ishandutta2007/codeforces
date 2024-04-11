#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        if(n==1)
            cout << "T" << endl;
        else{
            int sum =0;
            for(int i=0;i<n;i++) sum+=a[i];
            if(sum%2) cout << "T" << endl;
            else {
                sort(a,a+n);
                if(a[n-1]*2>sum){
                    cout << "T" << endl;
                }
                else{
                    cout << "HL" << endl;
                }
            }
        }
    }
}