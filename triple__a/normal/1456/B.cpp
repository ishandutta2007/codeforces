#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

int n;
int a[100007],b[100007];
int res=1e9;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    if (n>=200){
        cout<<1;
        return 0;
    }
    auto calc=[&](int l,int r){
        return b[r]^b[l-1];
    };
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) b[i]=b[i-1]^a[i];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=i;++j){
            for (int k=i+1;k<=n;++k){
                if (calc(j,i)>calc(i+1,k)){
                    res=min(res,k-j-1);
                }
            }
        }
    }
    if (res<1e9) cout<<res;
    else cout<<-1;
    return 0;
}