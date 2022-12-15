#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, q, i, x, y, ans;

int main(){
    for(scanf("%lld%lld",&n,&q);i<q;i++){
        scanf("%lld%lld",&y,&x); ans=0;
        if((x+y)%2) ans += n*n/2+(n*n%2);
        if(n%2==0){
            ans += (y-1)*n/2;
            ans += x/2+(x%2);
        }
        else{
            ans += (y-1)/2*n;
            ans += (y-1)%2*(n/2);
            if((x+y)%2==0&&(y-1)%2) ans++;
            ans += x/2+(x%2);
        }
        printf("%lld\n",ans);
    }
    return 0;
}