#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int MN = 1e5+5;
pair<int,int> arr[MN];
int n, m, i, x;
long long ans, tot;

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr+1,arr+m+1,[](pii i,pii j){return i.second>j.second;});
    for(i=1;i<=m;i++){
        if(i%2) tot=(i*(i-1)/2)+1;
        else tot=(i*(i-1)/2)+i/2;
        if(tot>n) break;
        ans += arr[i].second;
    }
    printf("%lld\n",ans);
    return 0;
}