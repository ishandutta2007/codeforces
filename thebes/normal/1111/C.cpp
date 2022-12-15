#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll n, k, A, B, pos[MN], i, x;
ll solve(ll x,ll y,ll p){
    int l = lower_bound(pos+1,pos+k+1,x)-pos-1;
    int r = upper_bound(pos+1,pos+k+1,y)-pos-2;
    if(l>r) return A;
    else if(p) return min((r-l+1)*B*(y-x+1),solve(x,x+(1<<(p-1))-1,p-1)+solve(x+(1<<(p-1)),y,p-1));
    else return B*(r-l+1);
}
int main(){
    for(scanf("%lld%lld%lld%lld",&n,&k,&A,&B),i=1;i<=k;i++)
        scanf("%lld",&pos[i]);
    sort(pos+1,pos+k+1);
    printf("%lld\n",solve(1,1<<n,n));
    return 0;
}