#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
struct nd{int a, b;}st[3*MN],init;
int n, m, arr[MN], i, x, y;

void build(int i,int s,int e){
    if(s>e) return;
    if(s != e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
        st[i].a=(st[2*i].a==(s+e)/2)?st[2*i+1].a:st[2*i].a;
        st[i].b=(st[2*i+1].b==(s+e)/2+1)?st[2*i].b:st[2*i+1].b;
    }
    else{
        st[i].a = (arr[s+1]-arr[s]>=0)?s:s-1;
        st[i].b = (arr[s+1]-arr[s]<=0)?s:s+1;
    }
}

nd qu(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else{
        nd l=qu(2*i,s,(s+e)/2,ss,se), r=qu(2*i+1,(s+e)/2+1,e,ss,se), res;
        res.a = (l.a==(s+e)/2)? r.a:l.a;
        res.b = (r.b==(s+e)/2+1)? l.b:r.b;
        return res;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&arr[i]);
    build(1,1,n-1);
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        if(x == y){
            printf("Yes\n");
            continue;
        }
        nd res = qu(1,1,n-1,x,y-1);
        if(res.a>=res.b-1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}