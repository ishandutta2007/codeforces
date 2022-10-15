#include<bits/stdc++.h>
#define PI pair<int,int> 
using namespace std;

const int maxn=1000007;
vector<PI> event;
int n,t,ans=0;
int val[maxn];
set<int> s;
int main(){
    scanf("%d",&t);
    while (t--){
        ans=0;
        scanf("%d",&n);
        event.clear();
        for (int i=1;i<=n;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            event.push_back({u,-i});
            event.push_back({v,i});
            val[i]=0;
        }
        sort(event.begin(),event.end());
        bool ck=false;
        int idx=0;
        for (auto &c:event){
            if (c.second<0) s.insert(-c.second);
            else s.erase(c.second);
            if (idx&&s.size()) val[idx]++;
            if (s.empty()) ans++;
            if (ck&&s.size()==1) idx=*s.begin();
            else idx=0;
            if (s.size()) ck=1;
            else ck=0;
        }
        int mx=0;
        for (int i=1;i<=n;++i){
            mx=max(mx,val[i]);
        }
        ans+=mx;
        if (ans==n) ans--;
        printf("%d\n",ans);
    }
    return 0;
}