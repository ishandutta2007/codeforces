#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,f[N],a[N],b[N],c[N],dep[N],cnt;
long long ans;
vector<int>vec;
vector<int>to[N];
void dfs(int x,int fa){
    f[x]=fa;
    dep[x]=dep[fa]+1;
    b[x]=++cnt;
    stable_sort(to[x].begin(),to[x].end(),[&](int k1,int k2){return a[k1]<a[k2];});
    for(int i:to[x]){
        if(i==fa)continue;
        dfs(i,x);
    }
    vec.push_back(x);
}
void solve(int x,int lim){
    if(a[x]<lim)return;
    c[x]=++cnt;
    for(int i:to[x])if(i!=f[x])solve(i,lim);
}
bool calc(int x,int aim){
    if(!x)return 0;
    if(a[x]==aim)return 1;
    return calc(f[x],aim);
}
void find(int x){
    if(x!=1){
        ans++;
        if(a[x]>a[f[x]]){puts("NO"),exit(0);}
        swap(a[x],a[f[x]]),find(f[x]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<a[1]-1;i++)if(a[vec[i-1]]!=i)return puts("NO"),0;else ans+=dep[vec[i-1]]-1;
    if(a[1]!=1){
        if(!calc(vec[a[1]-2],a[1]-1))return puts("NO"),0;
        for(int i=1;i<=n;i++)if(a[i]==a[1]-1){find(i);break;}
    }
    cnt=a[1]-1;
    solve(1,a[1]);
    for(int i=1;i<=n;i++)if(a[i]>=a[1])if(a[i]!=c[i])return puts("NO"),0;
    printf("YES\n%lld\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    return 0;
}