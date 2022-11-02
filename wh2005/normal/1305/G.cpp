#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int ,int >
#define mcp(x,y) make_pair(x,y)
#define fi first
#define se second
const int N = 2e6+9;
const int M = 20;
int n,m,a[N],f[N],sz[N];
int find(int x){if(x==-1) return -1;return x==f[x]?x:(f[x]=find(f[x]));}

pi mx[N],t[N];
int Max(int x,int y){
    if(x==-1) return y;if(y==-1) return x;
    if(a[x]>a[y]) return x;return y;
}
void upd(pi &x,int y,int c){
    if(x.fi==-1){x.fi=y;return ;}
    if(find(x.fi)==c){x.fi=Max(x.fi,y);return ;}
    if(a[y]>a[x.fi]){x.se=x.fi,x.fi=y;return ;}
    x.se=Max(x.se,y);return ;
}
void cpr(pi &x,pi y){
    if(find(x.fi)==find(y.fi)) x.fi=Max(x.fi,y.fi);
    if(a[y.fi]>a[x.fi]){x.se=Max(x.fi,y.se);x.fi=y.fi;}
    else{
        if(find(y.fi)!=find(x.fi)) x.se=Max(x.se,y.fi);
        if(y.se!=-1&&find(y.se)!=find(x.fi)) x.se=Max(x.se,y.se);
    }
    return ;
}

int fet(pi x,int c){
    if(find(x.fi)==c) return x.se;
    return x.fi;
}
void updd(pi &x,pi y){
    if(y.fi==-1||y.se==-1) return ;
    if(a[y.fi]+a[y.se]>a[x.fi]+a[x.se]) x=y;
    return ;
}

ll ans;

void merge(int x,int y){
    x=find(x),y=find(y);
    if(sz[x]>sz[y]) swap(x,y);
    // printf("%d %d\n",x,y);
    if(x!=y){
        f[x]=y;
        sz[y]+=sz[x];
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) ans-=(ll)a[i],m=max(m,a[i]);
    for(int i=0;i<=n;i++) f[i]=i,sz[i]=1;
    m=max(m,1);
    m=min((int)log2(m)+2,18);    
    int flag=1;pi unit=mcp(-1,-1),clr=mcp(0,0);
    int tim=0;
    while(flag){
        flag=0;
        for(int i=0;i<(1<<m);i++) mx[i]=unit,t[i]=clr;
        for(int i=0;i<=n;i++) upd(mx[a[i]],i,find(i));
        for(int j=0;j<m;j++){
            for(int i=0;i<(1<<m);i++){   
                if((i>>j)&1) continue;
                if(mx[i].fi==-1) continue;
                if(mx[i^(1<<j)].fi==-1) mx[i^(1<<j)]=mx[i];
                else cpr(mx[i^(1<<j)],mx[i]);
            }
        }
        for(int i=0;i<=n;i++){
            int ms=((1<<m)-1)^a[i];
            if(mx[ms].fi==-1) continue;
            updd(t[find(i)],mcp(fet(mx[ms],find(i)),i));
        }
        for(int i=0;i<=n;i++){
            if(t[i].fi!=-1&&t[i].se!=-1&&find(t[i].fi)!=find(t[i].se)){
                merge(t[i].fi,t[i].se);
                ans+=(ll)a[t[i].fi]+(ll)a[t[i].se];
                flag=1;
            }
        }
        tim++;
        // printf("%d %d %d\n",flag,tim,m);
        // if(tim>m+5) throw;
    }
    cerr<<tim<<endl;
    cout<<ans<<endl;
    return 0;
}