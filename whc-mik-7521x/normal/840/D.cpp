#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],cnt[N],ccnt[N],mi[N],n,m,t,ans[N];
struct node{
    int l,r,k,num;
    bool operator<(const node b)const{
        return l/t==b.l/t?r<b.r:l<b.l;
    }
}q[N];
void del(int x){
    mi[cnt[x]--]=1e9;
}
void dele(int x){
    cnt[x]--;
}
void ins(int x,int k){
    cnt[x]++;
    mi[cnt[x]]=min(mi[cnt[x]],x);
}
int inse(int x,int k){
    return ++cnt[x]>k?x:1e9;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    t=sqrt(n);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
        q[i].num=i;
    }
    stable_sort(q+1,q+m+1);
    int last=-1,ll=1,rr=0;
    memset(mi,127,sizeof mi);
    for(int i=1;i<=m;i++){
        if(q[i].l/t!=last){
            last=q[i].l/t;
            for(int o=ll;o<=rr;o++)del(a[o]);
            ll=(last+1)*t,rr=ll-1;
        }
        int kk=(q[i].r-q[i].l+1)/q[i].k;
        if(q[i].l/t==q[i].r/t){
            int now=1e9;
            for(int o=q[i].l;o<=q[i].r;o++){
                now=min(now,inse(a[o],kk));
            }
            ans[q[i].num]=now;
            for(int o=q[i].l;o<=q[i].r;o++){
                dele(a[o]);
            }
        }
        else{
            int now=1e9;
            while(rr<q[i].r)ins(a[++rr],kk);
            while(ll>q[i].l)now=min(now,inse(a[--ll],kk));
            ans[q[i].num]=min(now,mi[kk+1]);
            while(ll<(last+1)*t)dele(a[ll++]);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]>n?-1:ans[i]);
    }
    return  0;
}