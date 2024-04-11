#include <cstdio>
#include <algorithm>
using std::sort;

const int MAXN=200005;

int n,f[MAXN],id[MAXN];
bool vis[MAXN];

template <typename T>
inline void read(T &x){
    int ch,fl=0;
    while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
    while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
    if (fl) x=-x;
}

struct po{
    int l,r;
    bool operator <(const po &b)const{return l<b.l || (l==b.l && r<b.r);}
} a[MAXN];

inline bool cmp(const int &x,const int &y){
    return a[x].r<a[y].r || (a[x].r==a[y].r && a[x].l<a[y].l);
}

int main(){
    read(n);
    for (int i=1,x,w;i<=n;++i){
        read(x),read(w);
        a[i].l=x-w,a[i].r=x+w;
        id[i]=i;
    }
    sort(a+1,a+1+n);
    sort(id+1,id+1+n,cmp);
    for (int i=1,j=1,max_x=0;i<=n;++i){
        while (j<=n && a[id[j]].r<=a[i].l){
            if (max_x<f[id[j]]) max_x=f[id[j]];
            vis[id[j]]=1;
            ++j;
        }
        f[i]=max_x+1;
        if (vis[i]){
            if (max_x<f[i]) max_x=f[i];
        }
    }
    printf("%d\n",f[n]);
    return 0;
}