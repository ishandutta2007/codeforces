#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e5+10;

int n;
int q[N<<1],mark[N],alre[N];
vector <ii> ans;
map <ii,int> ma;

struct DSU{
    vector <int> ec;
    vector <int> et;
    int t,deg;
}mdsu[N];
int root(int x){
    if (mdsu[x].t<0) return x;
    mdsu[x].t=root(mdsu[x].t);
    return mdsu[x].t;
}
void merge(int x,int y){
    int rx=root(x),ry=root(y);
    if (rx==ry) return;
    if (mdsu[rx].t>mdsu[ry].t) swap(rx,ry);
    for(auto i:mdsu[ry].ec)
        mdsu[rx].ec.push_back(i);
    for(auto i:mdsu[ry].et)
        mdsu[rx].et.push_back(i);
    mdsu[ry].ec.clear();
    mdsu[ry].et.clear();
    mdsu[rx].t+=mdsu[ry].t;
    mdsu[rx].deg+=mdsu[ry].deg;
    mdsu[ry].t=rx;
}
struct graph{
    int v[N][2],h[N];
    vector <int> e[N];
    void read(){
        int x,y;
        REP(i,1,n){
            scanf("%d%d",&x,&y);
            v[i][0]=x;v[i][1]=y;
            e[x].push_back(i);
            e[y].push_back(i);
        }
    }
    bool circuit_detect(){
        q[1]=1;
        h[1]=1;
        int top=1,bot=1;
        while (top<=bot){
            int x=q[top++];
            for(auto i:e[x]){
                int y=v[i][0]+v[i][1]-x;
                if (!h[y]){
                    h[y]=1;
                    q[++bot]=y;
                }
            }
        }
        return count(h+1,h+n+1,1)!=n;
    }
};
graph cur,tar;
void prepare(){
    scanf("%d",&n);
    cur.read();
    tar.read();
}
ii topair(int x,int y){
    if (x>y) swap(x,y);
    return ii(x,y);
}
void solve(){
    /*///if there is circle then out
    if (cur.circuit_detect()||tar.circuit_detect()){
        printf("-1");
        return;
    }*/
    ///mark target edges
    REP(i,1,n){
        int x=tar.v[i][0],y=tar.v[i][1];
        ma[topair(x,y)]=i;
    }
    ///init dsu
    REP(i,1,n)
        FOR(j,0,1)
            mdsu[tar.v[i][j]].et.push_back(i);
    REP(i,1,n)
        FOR(j,0,1)
            mdsu[cur.v[i][j]].ec.push_back(i);
    FOR(i,1,n) mdsu[i].t=-1;
    REP(i,1,n){
        ii sel=topair(cur.v[i][0],cur.v[i][1]);
        if (ma[sel]){
            alre[ma[sel]]=1;
            mark[i]=1;
            merge(sel.X,sel.Y);
            continue;
        }
    }
    REP(i,1,n) if (!mark[i]){
        int x=root(cur.v[i][0]),y=root(cur.v[i][1]);
        mdsu[x].deg++,mdsu[y].deg++;
    }
//    FOR(i,1,n) cout<<mdsu[i].deg<<" \n"[i==n];
//    FOR(i,1,n) cout<<root(i)<<" \n"[i==n];
    int top=1,bot=0;
    FOR(i,1,n) if (mdsu[i].deg==1) q[++bot]=i;
    while (top<=bot){
        int x=root(q[top++]);
        if (!mdsu[x].deg) continue;
        while (mark[mdsu[x].ec.back()]) mdsu[x].ec.pop_back();
        int i=mdsu[x].ec.back();
        mdsu[x].ec.clear();
        mark[i]=1;
        int y=root(cur.v[i][0])==x?cur.v[i][1]:cur.v[i][0];
//        cout<<x<<" "<<y<<'\n';
        ///choose outcome edge
        while (alre[mdsu[x].et.back()]) mdsu[x].et.pop_back();
        int idx=mdsu[x].et.back();
        alre[idx]=1;
        ans.push_back(ii(i,idx));
        merge(tar.v[idx][0],tar.v[idx][1]);

        ///modified deg of component
        mdsu[root(x)].deg--,mdsu[root(y)].deg--;
        if (mdsu[root(y)].deg==1) q[++bot]=y;
//        cout<<x<<'\n';
//        FOR(i,1,n) cout<<mark[i]<<" \n"[i==n];
//        FOR(i,1,n) cout<<alre[i]<<" \n"[i==n];
    }
    printf("%d\n",int(ans.size()));
    for(auto i:ans)
        printf("%d %d %d %d\n",cur.v[i.X][0],cur.v[i.X][1],tar.v[i.Y][0],tar.v[i.Y][1]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}