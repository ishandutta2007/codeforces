#include<bits/stdc++.h>
using namespace std;
const int N = 200009;
int rt[N],tot,n,m;
struct segment{int L,R,sum,ans;}t[N*32];
void update(int c){t[c].sum=t[t[c].L].sum+t[t[c].R].sum;}
void modify(int &c,int l,int r,int x){
    if(!c) c=++tot;
    if(l==r){t[c].sum=1;return ;}
    int mid=(l+r)>>1;
    if(x<=mid) modify(t[c].L,l,mid,x);
    if(x>mid) modify(t[c].R,mid+1,r,x);
    update(c);
    return ;
}
bool query(int c,int l,int r,int x){
    if(!c) return 0;
    if(l==r) return 1;
    int mid=(l+r)>>1;
    if(x<=mid) return query(t[c].L,l,mid,x);
    if(x>mid) return query(t[c].R,mid+1,r,x);
}
void merge(int c,int p){
    if(!t[c].sum&&!t[p].sum) return ;
    if(!t[t[c].L].sum&&t[t[p].L].sum) t[c].L=t[p].L; 
    else if(t[t[c].L].sum&&t[t[p].L].sum) merge(t[c].L,t[p].L);
    if(!t[t[c].R].sum&&t[t[p].R].sum) t[c].R=t[p].R; 
    else if(t[t[c].R].sum&&t[t[p].R].sum) merge(t[c].R,t[p].R);
    update(c);
    return ;
}
int find(int c,int p,int l,int r){
    if(!c||!p) return 0;
    if(l==r) return 0;
    int ans=0;
    int mid=(l+r)>>1;
    if(query(t[c].L,l,mid,mid)&&query(t[p].R,mid+1,r,mid+1)) ans++;
    if(query(t[p].L,l,mid,mid)&&query(t[c].R,mid+1,r,mid+1)) ans++;
    ans+=find(t[c].L,t[p].L,l,mid);
    ans+=find(t[c].R,t[p].R,mid+1,r);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);tot=0;t[0].sum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if(query(rt[x],1,n,i-1)) ans++;
        if(query(rt[x],1,n,i+1)) ans++;
        modify(rt[x],1,n,i);
    }
    printf("%d\n",n-ans-1);
    for(int i=1;i<m;i++){
        int x,y;scanf("%d%d",&x,&y);
        ans+=find(rt[x],rt[y],1,n);
        merge(rt[x],rt[y]);
        rt[y]=rt[x];
        printf("%d\n",n-ans-1);
    }
    return 0;
}