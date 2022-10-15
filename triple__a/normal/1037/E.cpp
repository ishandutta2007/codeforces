#include<bits/stdC++.h>
using namespace std;

const int maxn=200007;
set<int> vec[maxn];
int l[maxn],r[maxn],n,m,k;
int ans[maxn],tmp=0;
bool vis[maxn];

void dl(int u){
    if (vis[u]||vec[u].size()>=k) return;
    vis[u]=1, tmp++;
    for (auto c:vec[u]){
        if (!vis[c]){
            vec[c].erase(u);
            dl(c);
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;++i){
        scanf("%d%d",&l[i],&r[i]);
        vec[l[i]].insert(r[i]);
        vec[r[i]].insert(l[i]);
    }
    for (int i=1;i<=n;++i){
        dl(i);
    }
    ans[m]=n-tmp;
    for (int i=m;i>0;--i){
        vec[l[i]].erase(r[i]);
        vec[r[i]].erase(l[i]);
        dl(l[i]); dl(r[i]);
        ans[i-1]=n-tmp;
    }
    for (int i=1;i<=m;++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}