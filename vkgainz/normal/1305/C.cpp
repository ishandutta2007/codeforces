#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;
    int m; cin >> m;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    if(n>m)
        cout << 0 << endl;
    else{
        ll prod = 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                prod*=1LL*(a[j]-a[i]);
                prod%=m;
            }
        }
        if(prod<0) prod+=m;
        cout<< prod << endl;
    }
}