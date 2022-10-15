#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;

int C[maxn],a[maxn],nxt[maxn],ret[maxn],l[maxn],r[maxn],head[maxn];
bool ck[maxn];
int n,m;

inline int lb(int u){
    return u&-u;
}

void update(int u,int val){
    for (int i=u;i<=n+m+1;i+=lb(i)){
        C[i]+=val;
    }
}

void add(int l,int r){
    update(l,1);
    update(r,-1);
}

int query(int u){
    int ans=0;
    for (int i=u;i>0;i-=lb(i)){
        ans+=C[i];
    }
    return ans;
} 


int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i){
        scanf("%d",&a[m+1-i]);
        ck[a[m+1-i]]=1;
    }
    for (int i=1;i<=n;++i){
        a[m+i]=i;
    }
    for (int i=1;i<=n+m;++i){
        if (ret[a[i]]) nxt[ret[a[i]]]=i;
        else head[a[i]]=i;
        ret[a[i]]=i;
    }
    for (int i=n+m;i>0;--i){
        add(i+1,nxt[i]?nxt[i]:n+m+1);
        r[a[i]]=max(query(nxt[i]),r[a[i]]);
    }
    for (int i=1;i<=n;++i){
        r[i]=max(r[i],query(head[i]));
    }
    for (int i=1;i<=n;++i){
        printf("%d %d\n",ck[i]?1:i,r[i]+1);
    }
    return 0;
}

/*4 1 5 3 1 2 3 4 5*/