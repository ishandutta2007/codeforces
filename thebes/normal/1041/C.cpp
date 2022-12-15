#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, m, d, i, ans[MN], cnt;
pair<int,int> arr[MN];
set<pair<int,int>> s;

int main(){
    for(scanf("%d%d%d",&n,&m,&d),i=1;i<=n;i++){
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }
    sort(arr+1,arr+n+1);
    for(i=1;i<=n;i++){
        auto it = s.begin();
        if(it==s.end()||it->first+d>=arr[i].first)
            s.insert({-1<<30, ++cnt});
        it = s.begin(); int id=it->second;
        s.erase(it);
        ans[arr[i].second] = id;
        s.insert({arr[i].first,id});
    }
    printf("%d\n",cnt);
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}