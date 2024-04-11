#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int main(){
    int n; cin >> n;
    int a[n+1];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    ll w,b;
    w = 0, b =0;
    for(int i=0;i<n;i++){
        if(i%2){
            w+=(a[i]/2);
            b+=(a[i]+1)/2;
        }
        else{
            w+=(a[i]+1)/2;
            b+=(a[i]/2);
        }
    }
    cout << min(w,b) << endl;
}