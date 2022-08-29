#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define fcout cout << fixed << setprecision(10)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n<2){
        cout<<-1;
        return 0;
    }
    int a[n];
    rep(i,0,n)cin>>a[i];
    if(n==2&&a[0]==a[1]){
        cout<<-1;
        return 0;
    }
    int m=min_element(a, a+n)-a+1;
    cout<<n-1<<endl;
    if(m==1){
        cout<<2;
        rep(i,3,n+1)cout<<' '<<i;
    }
    else{
        cout<<1;
        rep(i,2,n+1)if(m-i)cout<<' '<<i;
    }
}