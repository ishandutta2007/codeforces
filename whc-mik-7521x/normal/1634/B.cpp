#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],n,x,y,t;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        int now,tot=0;
        for(int i=1ll;i<=n;i++){
            cin>>now;
            tot^=now&1ll;
        }
        y=(y&1ll)^tot;
        if((x&1ll)==y)puts("Alice");
        else puts("Bob");
    }
    return  0;
}