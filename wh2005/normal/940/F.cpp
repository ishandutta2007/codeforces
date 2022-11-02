#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
int n,m,a[N],Ans[N],unit,bl[N],lt,rt,p[N];
struct Ques{int l,r,t,id;}q[N];
struct Mod{int x,y;}e[N];
bool cmp(Ques x,Ques y){
    return bl[x.l]==bl[y.l]?((bl[x.r]==bl[y.r]?(x.t<y.t):(x.r<y.r))):(x.l<y.l);
}
int c[N],w[N];
void M(int x,int d){
    if(c[a[x]]>0) w[c[a[x]]]--;
    c[a[x]]+=d;
    if(c[a[x]]>0) w[c[a[x]]]++;
}
void F(int x,int d,int l,int r){
    int u=e[x].x,v=e[x].y;e[x].y=a[u];
    if(u>=l&&u<=r){M(u,-1);a[u]=v;M(u,1);}
    else{a[u]=v;}
    return ;
}
int main(){
    scanf("%d%d",&n,&m);unit=pow(n,0.6667);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);p[i]=a[i];}
    int len=n;
    for(int i=1;i<=n;i++) bl[i]=(i-1)/unit+1;
    lt=0,rt=0;
    for(int i=1;i<=m;i++){
        int op,x,y;scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            lt++;q[lt].l=x,q[lt].r=y,q[lt].t=rt,q[lt].id=lt;
        }
        if(op==2){rt++;e[rt].x=x,e[rt].y=y,p[++len]=y;}
    }
    sort(p+1,p+len+1);len=unique(p+1,p+len+1)-p-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+len+1,a[i])-p;
    for(int i=1;i<=rt;i++) e[i].y=lower_bound(p+1,p+len+1,e[i].y)-p;
    sort(q+1,q+lt+1,cmp);
    int l=1,r=0,t=0;
    for(int i=1;i<=lt;i++){
        while(l<q[i].l) M(l++,-1);
        while(l>q[i].l) M(--l,1);
        while(r<q[i].r) M(++r,1);
        while(r>q[i].r) M(r--,-1);  
        while(t<q[i].t) F(++t,1,l,r);
        while(t>q[i].t) F(t--,-1,l,r);
        for(int j=1;j<=n;j++){
            if(w[j]==0){Ans[q[i].id]=j;break;}
        }
    }
    for(int i=1;i<=lt;i++) printf("%d\n",Ans[i]);
    return 0;
}