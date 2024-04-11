#include <bits/stdc++.h>
using namespace std;
const int N=150;
int s[N],d[N],c[N],cnt[N];
int ans[N];
int main(){
    int n,m;scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++)scanf("%i%i%i",&s[i],&d[i],&c[i]);
    for(int i=1;i<=n;i++){
        vector<pair<int,int>> v;
        bool ok=1;
        for(int j=1;j<=m;j++){
            if(i==d[j]&&cnt[j]<c[j]){
                printf("-1");
                return 0;
            }
            if(i==d[j]){
                ans[i]=m+1,ok=0;
                break;
            }
            if(cnt[j]<c[j]&&i>=s[j]){
                v.push_back({d[j],j});
            }
        }
        if(!ok)continue;
        if(!ok)continue;
        sort(v.begin(),v.end());
        if(v.empty()){ans[i]=0;continue;}
        cnt[v[0].second]++;
        ans[i]=v[0].second;
    }
    for(int i=1;i<=n;i++)printf("%i ",ans[i]);
    return 0;
}