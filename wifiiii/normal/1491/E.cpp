#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int fib[40];
const int maxn = 400005;
struct edge {
    int v,nxt,vis;
}es[maxn];
int head[maxn], tot=2;
void adde(int u,int v){es[tot]=edge{v,head[u],0}, head[u]=tot++;}
int sz[maxn];
void getsz(int u, int fa) {
    sz[u]=1;
    for(int i=head[u];i;i=es[i].nxt) {
        int v=es[i].v;
        if(v==fa || es[i].vis) continue;
        getsz(v, u);
        sz[u] += sz[v];
    }
}
int e,x,y,f=0;
void find(int u, int fa, int k) {
    if(sz[u]==fib[k-1] || sz[u]==fib[k-2]) {
        f=1;
        x=u;
        y=fa;
        e=-1;
        for(int i=head[u];i;i=es[i].nxt) {
            if(es[i].v==fa) {
                e=i;
                break;
            }
        }
        assert(e!=-1);
    }
    if(f) return;
    for(int i=head[u];i;i=es[i].nxt) {
        int v=es[i].v;
        if(v==fa || es[i].vis) continue;
        find(v, u, k);
    }
}
int solve(int u, int k) {
    if(k <= 4) return 1;
    getsz(u, 0);
    assert(sz[u] == fib[k]);
    f = 0;
    find(u, 0, k);
    if(!f) return 0;
    es[e].vis = es[e^1].vis = 1;
    int xx = x, yy = y;
    if(sz[x] == fib[k-1]) {
        if(!solve(xx, k - 1)) return 0;
        if(!solve(yy, k - 2)) return 0;
    } else {
        if(!solve(xx, k - 2)) return 0;
        if(!solve(yy, k - 1)) return 0;
    }
    return 1;
}
int main() {
    fib[1]=fib[2]=1;
    for(int i=3;i<28;++i) fib[i]=fib[i-1]+fib[i-2];
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int k=0;
    for(int i=27;i>=2;--i) {
        if(fib[i]==n) {
            k=i;
            break;
        }
    }
    if(!k) return cout<<"NO"<<endl,0;
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        adde(u,v);
        adde(v,u);
    }
    cout<<(solve(1,k)?"YES":"NO")<<endl;
}