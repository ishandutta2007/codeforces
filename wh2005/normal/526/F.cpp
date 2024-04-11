#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri register int
#define ll long long
#define ui unsigned int
il ll read(){
    bool f=true;ll x=0;
    register char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=false;ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    if(f) return x;
    return ~(--x);
}
il void write(const ll &x){if(x>9) write(x/10);putchar(x%10+'0');}
il void print(const ll &x) {x<0?putchar('-'),write(~(x-1)):write(x);putchar('\n');}
il ll max(const ll &a,const ll &b){return a>b?a:b;}
il ll min(const ll &a,const ll &b){return a<b?a:b;}
const int MAXN=3e5+7;
const int B=MAXN*2;
int n,root[MAXN*4];
struct Segt
{
    int cnt;
    int sta[MAXN*10],top;
    struct T
    {
        int c[2],siz;
    }t[MAXN<<4];
    int apply(){
        if(top) return sta[top--];
        return ++cnt;
    }
    void del(int u){
        t[u].c[0]=t[u].c[1]=t[u].siz=0;
        sta[++top]=u;
    }
    #define lc t[u].c[0]
    #define rc t[u].c[1]
    #define mid (L+R>>1)
    void update(int u){
        t[u].siz=0;
        if(lc) t[u].siz+=t[lc].siz;
        if(rc) t[u].siz+=t[rc].siz;
    }
    void modify(int &u,int pos,int w,int L=1,int R=n){
        if(!u) u=apply();
        if(L==R){
            t[u].siz+=w;
            return;
        }
        if(pos<=mid) modify(lc,pos,w,L,mid);
        else modify(rc,pos,w,mid+1,R);
        update(u);
    }
    void erase(int &u){
        if(!u) return;
        erase(lc);
        erase(rc);
        del(u),u=0;
    }
    int query(int u,int l,int r,int L=1,int R=n){
        if(!u) return 0;
        if(l==L&&r==R) return t[u].siz;
        if(r<=mid) return query(lc,l,r,L,mid);
        else if(l>mid) return query(rc,l,r,mid+1,R);
        else return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
    }
    #undef lc
    #undef rc 
    #undef mid
}T;
int a[MAXN];
ll ans;
struct node
{
    int mx,mn,pos;
    int typ;
}b[MAXN];
int mx[MAXN],mn[MAXN],mark[MAXN];
void solve(int l,int r){
    int mid=l+r>>1;
    // if(l==r){
    //     ++ans;
    //     return;
    // }
    if(r-l+1<=256){
        for(ri i=l;i<=r;++i){
            int mx=0,mn=n+1;
            for(ri j=i;j<=r;++j){
                mx=max(mx,a[j]);    
                mn=min(mn,a[j]);
                if(mx-mn==j-i) ++ans;
            }
        }
        return;
    }
    solve(l,mid),solve(mid+1,r);
    for(ri i=l;i<=r;++i) mx[i]=mn[i]=a[i];
    for(ri i=mid-1;i>=l;--i) mx[i]=max(mx[i+1],mx[i]),mn[i]=min(mn[i+1],mn[i]);
    for(ri i=mid+2;i<=r;++i) mx[i]=max(mx[i],mx[i-1]),mn[i]=min(mn[i],mn[i-1]);
    for(ri i=l;i<=mid;++i) b[i]=(node){mx[i],mn[i],i,0};
    for(ri i=mid+1;i<=r;++i) b[i]=(node){mx[i],mn[i],i,1};
    
    for(ri i=mid+1;i<=r;++i) mark[mx[i]]=1;
    for(ri i=l;i<=mid;++i) assert(!mark[mx[i]]);
    for(ri i=mid+1;i<=r;++i) mark[mx[i]]=0;

    for(ri i=mid+1;i<=r;++i) mark[mn[i]]=1;
    for(ri i=l;i<=mid;++i) assert(!mark[mn[i]]);
    for(ri i=mid+1;i<=r;++i) mark[mn[i]]=0;
    sort(b+l,b+r+1,[](const node &p,const node &q){return p.mn<q.mn;});
    //mxl>mxr,mnl<mnr
    for(ri i=l;i<=r;++i){
        if(b[i].typ==0&&b[i].mx-b[i].mn+b[i].pos>mid) T.modify(root[b[i].mx-b[i].mn+b[i].pos],b[i].mx,1);
        else ans+=T.query(root[b[i].pos],b[i].mx,n);
    }
    for(ri i=l;i<=r;++i)
        if(b[i].typ==0&&b[i].mx-b[i].mn+b[i].pos>mid) T.erase(root[b[i].mx-b[i].mn+b[i].pos]);
    //mxl<mxr,mnl<mnr
    for(ri i=l;i<=r;++i){
        if(b[i].typ==0) T.modify(root[B-b[i].mn+b[i].pos],b[i].mx,1);
        else ans+=T.query(root[B+b[i].pos-b[i].mx],1,b[i].mx);
    }
    for(ri i=l;i<=r;++i)
        if(b[i].typ==0) T.erase(root[B-b[i].mn+b[i].pos]);

    //mxl>mxr,mnl>mnr
    for(ri i=r;i>=l;--i){
        if(b[i].typ==0) T.modify(root[B+b[i].mx+b[i].pos],b[i].mx,1);
        else ans+=T.query(root[B+b[i].pos+b[i].mn],b[i].mx,n);
    }
    for(ri i=l;i<=r;++i)
        if(b[i].typ==0) T.erase(root[B+b[i].mx+b[i].pos]);

    //mxl<mxr,mnl>mnr
    for(ri i=mid+1;i<=r;++i){
        int p=i+mn[i]-mx[i];
        if(p>=l&&p<=mid&&mx[p]<mx[i]&&mn[p]>mn[i]) ++ans;
    }
}

int main(){
    // freopen("rand.in","r",stdin);
    // freopen("1.out","w",stdout);
    n=read();
    for(ri i=1;i<=n;++i){
        int x=read(),y=read();
        a[x]=y;
    }
    solve(1,n);
    print(ans);
    fprintf(stderr,"%.3lf",1.0*clock()/CLOCKS_PER_SEC);
    return 0;
}