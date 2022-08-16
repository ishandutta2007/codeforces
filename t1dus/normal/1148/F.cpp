#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,a[300005],b[300005];

signed main(){
    cin >> n;
    int sm = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
        sm += a[i];
    }
    if(sm < 0){
        for(int i = 1; i <= n; i ++) a[i] *= -1;
    }
    int ans = 0;
    for(int i = 0; i < 62; i ++){
        int cur = 0;
        for(int j = 1; j <= n; j ++){
            if((1LL<<i) <= b[j] and b[j] < (1LL<<(i+1))) cur += a[j];
        }
        if(cur > 0){
            for(int j = 1; j <= n; j ++){
                if(b[j]&(1LL<<i)) a[j] *= -1;
            }
            ans |= (1LL<<i);
        }
    }
    cout << ans << "\n";
}