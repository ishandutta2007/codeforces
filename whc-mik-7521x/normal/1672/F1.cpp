#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N],cnt[N],ans[N];
multiset<int>st[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),st[a[i]].insert(i),cnt[a[i]]++;
        vector<int>v;
        for(int i=1;i<=n;i++)if(cnt[i])v.push_back(i);
        while(v.size()){
            vector<int>res,now;
            for(int i:v){
                now.push_back(*st[i].begin());
                st[i].erase(st[i].begin());
                cnt[i]--;
            }
            for(int i=1;i<(int)v.size();i++)ans[now[i-1]]=v[i];
            ans[now.back()]=v.front();
            for(int i:v)if(cnt[i])res.push_back(i);
            v=res;
        }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        puts("");
    }
    return  0;
}