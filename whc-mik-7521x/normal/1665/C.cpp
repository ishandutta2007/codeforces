#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int t,n,m;
vector<int>vec;
void dfs(int x,int fa){
    int ct=0;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        ct++;
    }
    if(ct)vec.push_back(ct);
}
bool check(int x){
    int res=0;
    for(int i=0;i<m;i++){
        res+=max(0,vec[i]-x);
    }
    return res<=x;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)h[i]=0;
        cnt=0;
        vec.clear();
        vec.push_back(1);
        for(int i=2;i<=n;i++){
            int x;
            scanf("%d",&x);
            add(x,i);
            add(i,x);
        }
        dfs(1,0);
        stable_sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        m=vec.size();
        for(int i=0;i<(int)vec.size();i++){
            vec[i]=max(vec[i]+i-m,0);
        }
        int l=0,r=1e9,mid,ans=1e9;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid))r=mid-1,ans=mid;
            else l=mid+1;
        }
        printf("%d\n",ans+m);
    }
    return  0;
}