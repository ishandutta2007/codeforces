//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=2000005;

int T,n,m,nowid,nowc,ind,d[N],dfn[N],low[N],st[N],col[N],q1[N],q2[N];bool ins[N];

struct ed{int nxt,to;}G[N<<1];int lnk[N],pp;
void ae(int u,int v){G[++pp]=(ed){lnk[u],v},lnk[u]=pp;}

void tarjan(int u){
    dfn[u]=low[u]=++ind,ins[u]=1,st[++*st]=u;
    for(int i=lnk[u];i;i=G[i].nxt)
        if(!dfn[G[i].to]){
            tarjan(G[i].to);
            low[u]=min(low[u],low[G[i].to]);
        }else if(ins[G[i].to]){
            low[u]=min(low[u],dfn[G[i].to]);
        }
    if(dfn[u]==low[u]){
        ++nowc;
        do{
            col[st[*st]]=nowc;
            ins[st[*st]]=0;
        }while(st[(*st)--]!=u);
    }
}

signed main(){
	rd(T);
	while(T--){
	    rd(n),rd(m);nowc=0;
	    rep(_,1,m){
			int i,j;rd(i),rd(j);
			if(i==j)continue;
			ae(i,j);
	    }
	    rep(i,1,n)if(!dfn[i])
	        tarjan(i);
	    if(nowc==1){
	    	puts("No");
		}else{
			puts("Yes");
			rep(i,1,n)for(int j=lnk[i];j;j=G[j].nxt){
				int v=G[j].to;
				if(col[i]!=col[v])++d[col[i]];
			}
			int id=0;
			rep(i,1,nowc)if(d[i]==0){
				id=i;break;
			}
			*q1=*q2=0;
			rep(i,1,n)if(col[i]==id)q1[++*q1]=i;else q2[++*q2]=i;
		    pt(*q1,' '),pt(*q2,'\n');
		    rep(i,1,*q1)pt(q1[i],i==*q1?'\n':' ');
		    rep(i,1,*q2)pt(q2[i],i==*q2?'\n':' ');
		}
		rep(i,1,n)dfn[i]=low[i]=0,col[i]=0,d[i]=0,lnk[i]=0;
		pp=0;
	}
    return 0;
}