#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(i,x) for (i=x.begin();i!=x.end();++i)
#define mp make_pair
#define pb push_back
#define N 10000005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
int F[10],tot;
ll val[N],n,m;
int cmp(int a,int b) {if (a==b) return 0;return (a>b)?1:-1;}
void dfs(int p,int n){
    if (p>n) {
        if (n==2&&F[1]==F[2])return;++tot;
        rep(i,1,n)val[tot]=val[tot]*10+F[i];
        return;
    }
    rep(i,0,9) {
        F[p]=i;
        if (p>=3&&(!cmp(F[p-2],F[p-1])||cmp(F[p],F[p-1])!=cmp(F[p-2],F[p-1]))) continue;
        dfs(p+1,n);
    }
}
inline void prepare() {rep(i,1,7)for(F[1]=1;F[1]<=9;++F[1])dfs(2,i);}
int to[N],nxt[N],H[N],cnt2;
inline void ins(int x,int y) {to[++cnt2]=y;nxt[cnt2]=H[x];H[x]=cnt2;}
#define INF 100000000000000ll
#define mod 10000000
inline bool check(ll p) {
    int st[20],tot=0;
    for(;p;p/=10)st[++tot]=p%10;
    rep(i,2,tot-1)if(!cmp(st[i],st[i-1])||cmp(st[i],st[i-1])!=cmp(st[i],st[i+1]))return 0;
    return 1;
}
#define clr(x) memset(x,0,sizeof x)
int cnt[15][15],sum[N];
inline void work() {
    if (n>mod) {
        for (ll i=n;i<=INF;i+=n)if (check(i)&&--m==0) {cout<<i<<endl;return;}
        puts("-1");return;
    } else {
        rep(i,1,tot)if(val[i]%n==0&&--m==0){cout<<val[i]<<endl;return;}
        dep(i,tot,1)ins(val[i]%n,i);
        rep(i,0,n-1)if(H[i]){
            int v=(n-(ll)i*mod%n)%n;if(!H[v])continue;
            clr(cnt);For(j,v){
                int t=val[to[j]];
                if (t>mod/10)++cnt[t/(mod/10)][t/(mod/100)%10];
                else if (t>mod/100&&t/(mod/1000)%10<t/(mod/100)%10)++cnt[0][t/(mod/100)%10];
            }
            For(j,i){
                int p=to[j],a=val[p]%10,b=val[p]/10%10;
                if (val[p]<10){
                    rep(t1,a+1,9)dep(t2,t1-1,0)sum[p]+=cnt[t1][t2];
                    dep(t1,a-1,0)rep(t2,t1+1,9)sum[p]+=cnt[t1][t2];
                }
                else if (b>a)rep(t1,a+1,9)dep(t2,t1-1,0)sum[p]+=cnt[t1][t2];
                else dep(t1,a-1,0)rep(t2,t1+1,9)sum[p]+=cnt[t1][t2];
            } 
        }
        rep(i,1,tot) {
            if (m>sum[i])m-=sum[i];
            else {
                rep(j,1,tot) if((val[i]*mod+val[j])%n==0&&check(val[i]*mod+val[j])&&--m==0){
                    if (val[i]*mod+val[j]>INF) puts("-1");
                    else printf("%I64d%07I64d\n",val[i],val[j]);
                    return;
                }
            }
        }
    }
    puts("-1");
}
int main() {
    prepare();
    cin>>n>>m;
    work();
    return 0;
}