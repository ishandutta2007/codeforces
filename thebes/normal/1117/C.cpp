#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
typedef long long ll;
ll lo, hi, n, i, dx, dy, x, y, X, Y;
string s;

int main(){
    scanf("%lld%lld%lld%lld",&x,&y,&X,&Y);
    cin >> n >> s;
    lo = 1, hi = 3e9*n;
    while(lo<hi){
        ll m = (lo+hi)>>1;
        dx = dy = 0;
        for(i=1;i<=n;i++){
            ll c = (m/n)+(i<=m%n);
            if(s[i-1]=='U') dy+=c;
            else if(s[i-1]=='D') dy-=c;
            else if(s[i-1]=='L') dx-=c;
            else if(s[i-1]=='R') dx+=c;
        }
        if(abs(X-x-dx)+abs(Y-y-dy)<=m) hi=m;
        else lo=m+1;
    }
    if(lo>2e9*n) printf("-1\n");
    else printf("%lld\n",lo);
    return 0;
}