// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=1000005;

ll t[N],a[N];
ll L[N],R[N],disc[N<<1];
int dlen;
int n,v;

/*
struct SMT{
    #define ls (u<<1)
    #define rs (u<<1|1)
    int maxx[N<<3],tag[N<<3];
    void update(int u,int l,int r,int ql,int qr,int delta){
        if(ql<=l&&r<=qr)return ckmax(tag[u],delta),ckmax(maxx[u],delta),void();
        int mid=l+r>>1;
        if(ql<=mid)update(ls,l,mid,ql,qr,delta);
        if(qr>mid)update(rs,mid+1,r,ql,qr,delta);
        maxx[u]=max(maxx[ls],maxx[rs]);
    }
    int query(int u,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr)return maxx[u];
        int mid=l+r>>1,ret=tag[u];
        if(ql<=mid)ckmax(ret,query(ls,l,mid,ql,qr));
        if(qr>mid)ckmax(ret,query(rs,mid+1,r,ql,qr));
        return ret;
    }
}smt;
*/

const int inf=1e9;

struct Info{
    int x,y,id;
    friend bool operator < (const Info&x,const Info&y){
        return x.x<y.x;
    }
}info[N],tmps[N];

struct Fen{
    int c[N];
    Fen(){
        rep(i,0,N-1)c[i]=-inf;
    }
    void ins(int x,int dlt){
        while(x<=dlen)
            ckmax(c[x],dlt),x+=x&-x;
    }
    int qry(int x){
        int ret=-inf;
        while(x)
            ckmax(ret,c[x]),x^=x&-x;
        return ret;
    }
    void clr(int x){
        while(x<=dlen)
            c[x]=-inf,x+=x&-x;
    }
}tr;

int dp[N];

void cdq(int l,int r){
    if(l==r)return;
    int mid=l+r>>1;
    cdq(l,mid);
    // printf("now cdq [%d,%d]\n",l,r);
    rep(i,mid+1,r)tmps[i]=info[i];
    sort(tmps+mid+1,tmps+r+1);
    for(int i=mid+1,j=l;i<=r;i++){
        while(j<=mid&&info[j].x<=tmps[i].x){
            tr.ins(info[j].y,dp[info[j].id]);
            j++;
        }
        ckmax(dp[tmps[i].id],tr.qry(tmps[i].y)+1);
    }
    rep(i,l,r)tr.clr(info[i].y);
    cdq(mid+1,r);
    sort(info+l,info+r+1);
}

int main(){
    n=read(),v=read();
    rep(i,1,n)dp[i]=-inf;
    rep(i,1,n)t[i]=read();
    disc[++dlen]=0;
    rep(i,1,n){
        a[i]=read();
        L[i]=1ll*v*t[i]-a[i],R[i]=1ll*v*t[i]+a[i];
        disc[++dlen]=L[i],disc[++dlen]=R[i];
    }
    sort(disc+1,disc+dlen+1);
    dlen=unique(disc+1,disc+dlen+1)-disc-1;
    rep(i,0,n){
        L[i]=lower_bound(disc+1,disc+dlen+1,L[i])-disc;
        R[i]=lower_bound(disc+1,disc+dlen+1,R[i])-disc;
    }
    rep(i,0,n)info[i].x=L[i],info[i].y=R[i],info[i].id=i,assert(info[i].y>0);
    cerr<<"!\n";
    cdq(0,n);
    print(*max_element(dp,dp+n+1),'\n');
    return 0;
}