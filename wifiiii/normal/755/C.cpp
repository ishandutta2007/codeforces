#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 100005;
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    par[x]=y;
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) par[i]=i;
    for(int i=1;i<=n;++i) {
        int u;
        cin>>u;
        merge(u,i);
    }
    int ans=0;
    for(int i=1;i<=n;++i) if(i==find(i)) ++ans;
    cout<<ans<<endl;
}