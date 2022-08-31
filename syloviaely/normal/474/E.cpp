#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define reu(i,a) for(int i = h[a];~i;i = n1[i])

typedef long long ll;
typedef long double db;

template <class T> inline void read(T &x){
    char ch = getchar();    int f = 1;  while((ch != '-') && (ch < '0' || ch > '9'))    ch = getchar();
    if(ch == '-')   f = 0, x = 0;   else    x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9')   x = x * 10 + ch - 48, ch = getchar();
    if(!f)  x = -x;
}
template <class T> inline void read(T &x,T &y){read(x);read(y);}
template <class T> inline void read(T &x,T &y,T &z){read(x);read(y);read(z);}
template <class T> inline void read(T &x,T &y,T &z,T &o){read(x);read(y);read(z);read(o);}

int _t[20];
template <class T> inline void out(T x,int ln = 1){
    if(!x)  putchar('0');
    else{
        if(x < 0)   putchar('-'),x = -x;
        for(_t[0] = 0;x;x /= 10)    _t[++ _t[0]] = x % 10;
        dwn(i,_t[0],1)  putchar(_t[i] + 48);
    }
    if(ln)  putchar('\n');
}

/*...........................................................................................................*/

#define N 300010

int seg[N << 2],pos[N << 2];
int f[N],g[N];
ll h[N],bin[N];
int a[N],n,d;

#define pr pair<int,int>
#define ls (x << 1)
#define rs (x << 1 | 1)

void upd(int x){
    if(seg[ls] > seg[rs]){
        seg[x] = seg[ls];
        pos[x] = pos[ls];
    }else{
        seg[x] = seg[rs];
        pos[x] = pos[rs];
    }
}

pr ask(int ql,int qr,int l,int r,int x){
    if(ql > qr) return mp(0,0);
    if(ql <= l && r <= qr)  return mp(seg[x],pos[x]);
    pr ret = mp(0,0);
    int mid = (l + r) >> 1;
    if(ql <= mid)   ret = max(ret, ask(ql,qr,l,mid,ls));
    if(mid < qr)    ret = max(ret, ask(ql,qr,mid + 1,r,rs));
    return ret;
}

void modify(int p,int v,int k,int l,int r,int x){
    if(l == r){
        if(v > seg[x]){
            seg[x] = v;
            pos[x] = k;
        }
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid)    modify(p,v,k,l,mid,ls);
    else        modify(p,v,k,mid + 1,r,rs);
    upd(x);
}
    
int main(){
    read(n,d);
    int cnt = 0;
    rep(i,1,n)  read(h[i]),bin[++ cnt] = h[i],bin[++ cnt] = h[i] + d,bin[++ cnt] = h[i] - d;
    sort(bin + 1,bin + cnt + 1);
    cnt = unique(bin + 1,bin + cnt + 1) - bin - 1;
    rep(i,1,n)  a[i] = lower_bound(bin + 1,bin + cnt + 1,h[i]) - bin;
    int a1 = 0,a2;
    dwn(i,n,1){
        int l = upper_bound(bin + 1,bin + cnt + 1,h[i] - d) - bin - 1;
        int r = lower_bound(bin + 1,bin + cnt + 1,h[i] + d) - bin;
        pr t = max(ask(1,l,1,cnt,1), ask(r,cnt,1,cnt,1));
        f[i] = t.fi + 1;
        g[i] = t.se;
        if(f[i] > a1){
            a1 = f[i];
            a2 = i;
        }
        modify(a[i],f[i],i,1,cnt,1);
    }
    out(a1);
    printf("%d",a2);
    int x = g[a2];
    while(x){
        printf(" %d",x);
        x = g[x];
    }
    return 0;
}