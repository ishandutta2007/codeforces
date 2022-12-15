#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 5e5+5, MS = 700;
ll a[MN], b[MS+5][MS+5], q, i, j, t, x, y, r;

int main(){
    for(scanf("%lld",&q);q;q--){
        scanf("%lld%lld%lld",&t,&x,&y);
        if(t==1){
            a[x] += y;
            for(i=1;i<=MS;i++){
                r = x%i;
                b[i][r] += y;
            }
        }
        else{
            r = 0;
            if(x>MS){
                for(i=y;i<MN;i+=x) r += a[i];
                printf("%lld\n",r);
            }
            else printf("%lld\n",b[x][y]);
        }
    }
    return 0;
}