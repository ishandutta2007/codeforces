#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> lli;

#define X first
#define Y second

const int N=1e5+10;
const int alp=26;

const ll inf=1e16;

string s;
int n,a[N];
int troot;

int son[N][2];
int root[N];
int deg[N];

set <int> mse[N];


int q[N];
void BFS(){
    int top=1,bot=1;
    while (top<=bot){
        int x=q[top++];
        for(auto i:son[x]) if (i!=-1) q[++bot]=i;
    }
}
int solve(){
    for(int pha=n;pha>=1;pha--){
        int x=q[pha];
        if (son[x][0]==-1&&son[x][1]==-1){
            root[x]=x;
            mse[x].insert(a[x]);
            continue;
        }
        if (son[x][0]!=-1){
            int tar=root[son[x][0]];
            auto idx=mse[tar].lower_bound(a[x]);
            for(;idx!=mse[tar].end();){
                auto tmp=idx++;
                mse[tar].erase(tmp);
            }
        }
        if (son[x][1]!=-1){
            int tar=root[son[x][1]];
            for(auto idx=mse[tar].begin();idx!=mse[tar].end();){
                auto tmp=idx++;
                if (*tmp<a[x]) mse[tar].erase(tmp);
                else break;
            }
        }
        if (son[x][0]==-1||(son[x][1]!=-1&&mse[root[son[x][1]]].size()<mse[root[son[x][0]]].size()))
            root[x]=root[son[x][1]];
        else root[x]=root[son[x][0]];
        for(int i=0;i<=1;i++) if (son[x][i]!=-1&&root[son[x][i]]!=root[x])
            for(auto j:mse[root[son[x][i]]])
                mse[root[x]].insert(j);
        mse[root[x]].insert(a[x]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=mse[root[q[1]]].count(a[i]);
    return n-ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",a+i);
        for(int j=0;j<=1;j++) {
            scanf("%d",son[i]+j);
            if (son[i][j]!=-1) deg[son[i][j]]++;
        }
    }
    q[1]=1;
    while (deg[q[1]]) q[1]++;
    BFS();
    cout<<solve();
}