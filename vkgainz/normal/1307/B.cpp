#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x; cin >> x;
        int a[n];
        int most = 0;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) most = max(most,a[i]);
        if(most>x){
            bool found = false;
            for(int i=0;i<n;i++){
                if(a[i]==x) found = true;
            }
            if(found) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else{
            cout << (x+most-1)/most << endl;
        }
    }
}