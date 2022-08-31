#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx","avx2","fma")

#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    while(m --){
        int type,l,r,x; cin >> type >> l >> r >> x;
        if(type == 1){
            for(int i = l; i <= r; i ++){
                if(a[i] > x) a[i] -= x;
            }
        }
        else{
            int ans = 0;
            for(int i = l; i <= r; i ++){
                if(a[i] == x) ans++;
            }
            cout << ans << "\n";
        }
    }
}