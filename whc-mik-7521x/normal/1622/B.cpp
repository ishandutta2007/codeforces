#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,p[N],li[N],ans[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        vector<pair<int,int>>v;
        vector<pair<int,int>>u;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%1d",&x);
            if(!x)u.push_back({p[i],i});
            else v.push_back({p[i],i});
        }
        sort(u.begin(),u.end());
        sort(v.begin(),v.end());
        for(int i=0;i<(int)u.size();i++){
            ans[u[i].second]=i+1;
        }
        for(int i=0;i<(int)v.size();i++){
            ans[v[i].second]=u.size()+i+1;
        }
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        puts("");
    }
    return  0;
}