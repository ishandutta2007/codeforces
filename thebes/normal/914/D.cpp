#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 5e5+5;
int st[10*MN], n, q, i, x, y, k, arr[MN];
void build(int i,int s,int e){
    if(s != e){
        build(2*i,s,(s+e)/2); build(2*i+1,(s+e)/2+1,e);
        st[i] = __gcd(st[2*i], st[2*i+1]);
    }
    else st[i] = arr[s];
}
void upd(int i,int s,int e,int idx){
    if(s != e){
        if((s+e)/2 < idx) upd(2*i+1,(s+e)/2+1,e,idx);
        else upd(2*i,s,(s+e)/2,idx);
        st[i] = __gcd(st[2*i], st[2*i+1]);
    }
    else st[i] = arr[s];
}
int gcd(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return gcd(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return gcd(2*i,s,(s+e)/2,ss,se);
    else return __gcd(gcd(2*i+1,(s+e)/2+1,e,ss,se),gcd(2*i,s,(s+e)/2,ss,se));
}
bool qu(int i,int s,int e,int ss,int se,int k){
    if(st[i]%k==0) return 1;
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se,k);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se,k);
    else{
        int l=gcd(2*i,s,(s+e)/2,ss,se),r=gcd(2*i+1,(s+e)/2+1,e,ss,se);
        if((l%k)&&(r%k)) return 0;
        else if(l%k) return qu(2*i,s,(s+e)/2,ss,se,k);
        else return qu(2*i+1,(s+e)/2+1,e,ss,se,k);
    }
}
int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n);
    for(scanf("%d",&q);q;q--){
        scanf("%d%d%d",&i,&x,&y);
        if(i == 1){
            scanf("%d",&k);
            printf("%s\n",(qu(1,1,n,x,y,k))?"YES":"NO");
        }
        else{
            arr[x] = y;
            upd(1,1,n,x);
        }
    }
    return 0;
}