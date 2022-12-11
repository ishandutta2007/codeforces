#include<bits/stdc++.h>
using namespace std;
const int N=3e7+10;
struct seg{
    int l,r,add,mi,mx;
}t[N];
int n,k,cnt;
int ty(int l,int r,int mi,int mx){
    cnt++;
    t[cnt].mi=mi;
    t[cnt].mx=mx;
    return cnt;
}
void pushdown(int rt){
    t[rt].mi=t[t[rt].l].mi;
    t[rt].mx=t[t[rt].r].mx;
}
void pushup(int rt){
    int l=t[rt].l,r=t[rt].r;
    t[l].mi+=t[rt].add;
    t[l].mx+=t[rt].add;
    t[r].mi+=t[rt].add;
    t[r].mx+=t[rt].add;
    t[l].add+=t[rt].add;
    t[r].add+=t[rt].add;
    t[rt].add=0;
}
void upd(int l,int r,int rt,int k){
    if(t[rt].mi>k){
        t[rt].add-=1;
        t[rt].mi-=1;
        t[rt].mx-=1;
        return;
    }
    if(t[rt].mx<k){
        t[rt].add+=1;
        t[rt].mi+=1;
        t[rt].mx+=1;
        return;
    }
    if(t[rt].mi==k&&t[rt].mx==k){
        return;
    }
    int mid=(l+r)>>1;
    if(!t[rt].l&&!t[rt].r){
        t[rt].l=ty(l,mid,l,mid);
        t[rt].r=ty(mid+1,r,mid+1,r);
    }
    if(t[rt].add!=0)pushup(rt);
    upd(l,mid,t[rt].l,k);
    upd(mid+1,r,t[rt].r,k);
    pushdown(rt);
}
int query(int l,int r,int rt,int d){
    if(!t[rt].l)return t[rt].add;
    int mid=(l+r)>>1;
    if(t[rt].add!=0)pushup(rt);
    if(mid>=d)return t[rt].add+query(l,mid,t[rt].l,d);
    if(mid<d)return t[rt].add+query(mid+1,r,t[rt].r,d);
    return 0;
}
int main(){
    scanf("%d",&n);
    int an=0;
    ty(0,(int)1e9,0,(int)1e9);
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d",&p);
        upd(0,(int)1e9,1,p);
        scanf("%d",&k);
        for(int o=1;o<=k;o++){
            int x;
            scanf("%d",&x);
            x=(x+an)%((int)1e9+1);
            an=query(0,(int)1e9,1,x)+x;
            printf("%d\n",an);
        }
    }
    return  0;
}