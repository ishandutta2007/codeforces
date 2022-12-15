#include <bits/stdc++.h>
using namespace std;

const int MN = 5005;
int n, cnt, i, j, deg[MN];
pair<int,int> arr[MN];
vector<int> ans;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j) continue;
            if(arr[i].first<arr[j].second&&arr[i].second>arr[j].first)
                deg[i]++, deg[j]++, cnt++;
        }
    }
    for(i=1;i<=n;i++){
        if(deg[i] == cnt)
            ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(auto v : ans) printf("%d ",v);
    return 0;
}