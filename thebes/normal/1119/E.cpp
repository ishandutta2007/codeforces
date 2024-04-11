#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
typedef long long ll;
ll arr[MN], n, ans, i, x;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    for(i=1;i<=n;i++){
        ll mx = min(x,arr[i]/2);
        if((arr[i]-2*mx)%3>mx){
            ans += arr[i]/3;
            arr[i] %= 3;
            if(arr[i]>=2&&x){x--; arr[i]-=2;}
            x += arr[i];
        }
        else{
            ans += mx;
            arr[i] -= 2*mx; x -= mx;
            ans += arr[i]/3;
            arr[i] %= 3;
            x += arr[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}