#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
typedef pair<int,int> pii;
pii a[MN], b[MN], arr[MN];
int n, i, ans;
pii cmp(pii i,pii j){
    return make_pair(max(i.first,j.first),min(i.second,j.second));
}

int main(){
    a[0]={0,1e9+7};
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d%d",&arr[i].first,&arr[i].second);
        a[i] = cmp(a[i-1],arr[i]);
    }
    b[n+1]={0,1e9+7};
    for(i=n;i>=1;i--){
        b[i]=cmp(b[i+1],arr[i]);
    }
    for(i=1;i<=n;i++){
        pii res = cmp(a[i-1],b[i+1]);
        ans = max(ans, res.second-res.first);
    }
    printf("%d\n",ans);
    return 0;
}