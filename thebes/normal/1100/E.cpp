#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
struct edge{int x, y, w, id;}arr[MN];
int N, M, i, x, y, w, lo, hi, st[MN], vs[MN], f, dep[MN], ds[MN], use[MN], ord[MN], in[MN];
vector<int> ans, adj[MN];
struct idk{int x,w,id;};
vector<idk> vec[MN];
stack<int> s;
void dfs(int n){
    st[n] = vs[n] = 1;
    for(auto v : adj[n]){
        if(st[v]) f = 1;
        if(!vs[v]) dfs(v);
    }
    st[n] = 0;
}
int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}
void dfs2(int n){
    vs[n] = 1;
    for(auto v : adj[n])
        if(!vs[v]) dfs2(v);
    s.push(n);
}

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
        scanf("%d%d%d",&arr[i].x,&arr[i].y,&arr[i].w);
        arr[i].id = i;
    }
    sort(arr+1,arr+M+1,[](edge i,edge j){return i.w>j.w;});
    lo = 1, hi = M+1;
    while(lo<hi){
        int m = lo+hi>>1; f = 0;
        memset(st, 0, sizeof(st));
        memset(vs, 0, sizeof(vs));
        for(i=1;i<=N;i++) adj[i].clear();
        for(i=1;i<=m;i++) adj[arr[i].x].push_back(arr[i].y);
        for(i=1;i<=N;i++){
            if(!vs[i]) dfs(i);
        }
        if(f) hi = m;
        else lo=m+1;
    }
    if(lo==M+1){
        printf("0 0\n");
        return 0;
    }
    else{
        printf("%d ",arr[lo].w);
        memset(vs, 0, sizeof(vs));
        for(i=1;i<=N;i++) ds[i]=i, ord[i]=i;
        for(i=1;i<=N;i++) adj[i].clear();
        for(i=1;i<=M;i++){
            if(fnd(arr[i].x)!=fnd(arr[i].y)||i<lo){
                adj[arr[i].x].push_back(arr[i].y); in[arr[i].y]++;
                use[i] = 1; ds[fnd(arr[i].x)]=fnd(arr[i].y);
            }
        }
        sort(ord+1,ord+N+1,[](int i,int j){return in[i]<in[j];});
        for(i=1;i<=N;i++){
            if(!vs[ord[i]]) dfs2(ord[i]);
        }
        i = N;
        while(s.size()){
            dep[s.top()]=i;
            i--; s.pop();
        }
        for(i=1;i<=M;i++){
            if(!use[i]){
                if(dep[arr[i].y]>dep[arr[i].x]){
                    ans.push_back(arr[i].id);
                }
            }
        }
        printf("%d\n",ans.size());
        for(auto v : ans) printf("%d ",v);
        printf("\n");
    }
    return 0;
}