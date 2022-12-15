#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 3e5+5, MS = 550;
ll lol[MS][MS], arr[MN], n, q, i, j, x, y, ans[MN];
vector<pair<ll,ll>> qu[MN];

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    for(scanf("%lld",&q),i=1;i<=q;i++){
        scanf("%lld%lld",&x,&y);
        if(y<MS-10) qu[x].push_back({y,i});
        else{
            ll tmp = 0;
            for(j=x;j<=n;j+=y)
                tmp += arr[j];
            ans[i] = tmp;
        }
    }
    for(i=n;i>=1;i--){
        for(j=1;j<MS-5;j++){
            lol[i%MS][j]=arr[i]+lol[(i+j)%MS][j];
        }
        for(auto v : qu[i])
            ans[v.second]=lol[i%MS][v.first];
    }
    for(i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}