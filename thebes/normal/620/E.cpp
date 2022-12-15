#include <bits/stdc++.h>
using namespace std;

const int MN = 4e5+5;
struct nd{long long a, b;}st[3*MN];
int sta[MN], en[MN], n, m, i, x, y, c, init[MN], t, ord[MN], dep[MN];
vector<int> adj[MN];

void dfs(int n,int p,int d){
    sta[n]=++t; dep[n]=d;
    for(auto v : adj[n])
        if(v != p) dfs(v, n, d++);
    en[n] = t;
}

inline void push_down(int i,int s,int e){
    if(!st[i].b) return;
    st[i].a = st[i].b;
    if(s!=e){
        st[2*i].b = st[i].b;
        st[2*i+1].b = st[i].b;
    }
    st[i].b = 0;
}

void upd(int i,int s,int e,int ss,int se,int c){
    push_down(i,s,e);
    if(s>=ss&&e<=se){
        st[i].a = st[i].b = 1LL<<c;
        push_down(i,s,e);
    }
    else{
        if((s+e)/2<ss){
            upd(2*i+1,(s+e)/2+1,e,ss,se,c);
            push_down(2*i,s,(s+e)/2);
        }
        else if((s+e)/2>=se){
            upd(2*i,s,(s+e)/2,ss,se,c);
            push_down(2*i+1,(s+e)/2+1,e);
        }
        else{
            upd(2*i,s,(s+e)/2,ss,se,c);
            upd(2*i+1,(s+e)/2+1,e,ss,se,c);
        }
        st[i].a = st[2*i].a|st[2*i+1].a;
    }
}

long long qu(int i,int s,int e,int ss,int se){
    push_down(i,s,e);
    if(s>=ss&&e<=se) return st[i].a;
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return qu(2*i,s,(s+e)/2,ss,se)|qu(2*i+1,(s+e)/2+1,e,ss,se);
}

inline int cnt(long long idk){
    int ret = 0;
    while(idk){
        ret ++;
        idk -= idk&-idk;
    }
    return ret;
}

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
        scanf("%d",&init[i]);
    for(i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0,1);
    for(i=1;i<=n;i++) ord[i]=i;
    sort(ord+1,ord+n+1,[](int i,int j){return dep[i]<dep[j];});
    for(i=1;i<=n;i++)
        upd(1,1,n,sta[ord[i]],sta[ord[i]],init[ord[i]]);
    for(;m;m--){
        scanf("%d%d",&x,&y);
        if(x==2) printf("%d\n",cnt(qu(1,1,n,sta[y],en[y])));
        else{scanf("%d",&c); upd(1,1,n,sta[y],en[y],c);}
    }
    return 0;
}