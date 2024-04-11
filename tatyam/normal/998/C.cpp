#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define fcout cout << fixed << setprecision(10)
int main(){
#define int ll
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    bool zero=false;
    int cnt=0;
    rep(i, 0, n){
        if(s[i]=='1')zero=false;
        else if(!zero){
            zero=true;
            cnt++;
        }
    }
    if(!cnt){
        cout<<0;
        return 0;
    }
    if(x<y)cout<<(cnt-1)*x+y;
    else cout<<cnt*y;
}