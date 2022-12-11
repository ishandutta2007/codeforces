#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>ans;
int t,n,a[N],cnt[N],res;
int solve(int x){
    map<int,bool>mp;
    int now=0;
    while(x<=n){
        if(cnt[now]){
            while(a[x]!=now)mp[a[x]]=1,cnt[a[x++]]--;
            mp[a[x]]=1,cnt[a[x++]]--;
            while(mp.find(now)!=mp.end())now++;
        }
        else return res++,ans.push_back(now),cnt[a[x]]-=!now,x+!now;
    }
    return res++,ans.push_back(now),cnt[a[x]]-=!now,x+!now;
}
int main(){
    scanf("%d",&t);
    while(t--){
        res=0;
        scanf("%d",&n);
        ans.clear();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
        int now=1;
        while(now<=n)now=solve(now);
        printf("%d\n",res);
        for(int i=0;i<res;i++)printf("%d ",ans[i]);
        puts("");
        for(int i=1;i<=n;i++)cnt[a[i]]=0;
    }
    return  0;
}