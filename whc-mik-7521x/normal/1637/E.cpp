#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int t,n,m,a[N],x,y;
vector<int>que;
vector<int>al[N];
set<pair<int,int>>pd;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        stable_sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            al[upper_bound(a+1,a+n+1,a[i])-lower_bound(a+1,a+n+1,a[i])].push_back(a[i]);
            que.push_back(upper_bound(a+1,a+n+1,a[i])-lower_bound(a+1,a+n+1,a[i]));
        }
        stable_sort(que.begin(),que.end());
        que.erase(unique(que.begin(),que.end()),que.end());
        for(auto i:que){
            stable_sort(al[i].begin(),al[i].end());
            al[i].erase(unique(al[i].begin(),al[i].end()),al[i].end());
            reverse(al[i].begin(),al[i].end());
        }
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            pd.insert(make_pair(x,y));
            pd.insert(make_pair(y,x));
        }
        long long ans=0;
        for(int o=que.size()-1;o>=0;o--){
            for(int p=o;p>=0;p--){
                for(int j:al[que[o]]){
                    for(int q:al[que[p]]){
                        if(pd.find(make_pair(j,q))==pd.end()&&j!=q){
                            ans=max(ans,1ll*(j+q)*(que[o]+que[p]));
                            break;
                        }
                    }
                }
            }
        }
        printf("%lld\n",ans);
        for(auto i:que){
            al[i].clear();
        }
        que.clear();
        pd.clear();
    }
    return  0;
}