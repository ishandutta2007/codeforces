#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
int sum[maxn<<2];
int num[maxn<<2];
int add[maxn<<2];
int n,k,q;
int line[maxn];
int qx,qy;
void pushdown(int l,int r,int o){
    if(l==r)return;
    int mid=((r-l)>>1)+l;
    if(add[o]!=0){
        add[o<<1]+=add[o];
        add[o<<1|1]+=add[o];
        sum[o<<1]+=(l+1-mid)*add[o];
        sum[o<<1|1]+=(r-mid)*add[o];
        add[o]=0;
    }
}
void maintain(int o){
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void update(int l,int r,int o){
    pushdown(l,r,o);
    if(qx<=l&&r<=qy){
        sum[o]+=r-l+1;
        add[o]+=1;
        return;
    }
    int mid=((r-l)>>1)+l;
    if(qx<=mid) update(l,mid,o<<1);
    if(mid<qy) update(mid+1,r,o<<1|1);
    maintain(o);
}
int query(int l,int r,int o){
    pushdown(l,r,o);
    if(l==r) return sum[o];
    int mid=((r-l)>>1)+l;
    if(qx<=mid)return query(l,mid,o<<1);
    else return query(mid+1,r,o<<1|1);
}
void statics(int l,int r,int o){
    if(l==r){
        num[o]+=line[l];
        return;
    }
    int mid=((r-l)>>1)+l;
    statics(l,mid,o<<1);
    statics(mid+1,r,o<<1|1);
    num[o]=num[o<<1]+num[o<<1|1];
}
int get(int l,int r,int o){
    if(qx<=l&&r<=qy)return num[o];
    int mid=((r-l)>>1)+l;
    int ans=0;
    if(qx<=mid)ans+=get(l,mid,o<<1);
    if(mid<qy)ans+=get(mid+1,r,o<<1|1);
    return ans;
}
int main(){
    /*freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);*/
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&qx,&qy);
        update(1,maxn,1);
    }
    for(int i=1;i<maxn;i++){
        qx=i;
        int d=query(1,maxn,1);
        if(d>=k) line[i]=1;
    }
    statics(1,maxn,1);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qx,&qy);
        printf("%d\n",get(1,maxn,1));
    }
    return 0;
}