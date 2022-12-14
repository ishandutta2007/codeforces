#include <bits/stdc++.h>
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,ar[N];
struct A{
    int l,r;ll s;int len,al,ar;
}info[N<<2];
A operator+(A a,A b){
    A c;
    bool f=a.ar<=b.al;
    c.l=(a.l==a.len&&f?a.l+b.l:a.l);
    c.r=(b.r==b.len&&f?b.r+a.r:b.r);
    c.len=a.len+b.len;
    c.s=a.s+b.s;
    if(f)c.s+=(ll)a.r*b.l;
    c.al=a.al;
    c.ar=b.ar;
    return c;
}
void pull(int o){
    info[o]=info[lo]+info[ro];
}
void build(int o=1,int l=1,int r=n){
    if(l==r){
        info[o]={1,1,1,1,ar[l],ar[l]};
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    pull(o);
}
void modify(int p,int v,int o=1,int l=1,int r=n){
    if(l==r){
        info[o].al=info[o].ar=ar[l];
        return;
    }
    if(p<=mid)modify(p,v,lo,l,mid);
    else modify(p,v,ro,mid+1,r);
    pull(o);
}
A query(int ql,int qr,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        return info[o];
    }
    A ret{-1};
    if(ql<=mid)ret=query(ql,qr,lo,l,mid);
    if(qr>mid){
        auto a=query(ql,qr,ro,mid+1,r);
        if(ret.l==-1)ret=a;
        else ret=ret+a;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
//    freopen("C.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>ar[i];
    build();
    while(m--){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
            ar[x]=y;
            modify(x,y);
        }
        else if(op==2){
            int l,r;cin>>l>>r;
            cout<<query(l,r).s<<endl;
        }
    }
}