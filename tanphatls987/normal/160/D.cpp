#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("111d.inp","r",stdin)
#define OUTPUT freopen("111d.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,x,y,w,h[N],t[N],ans[N];
ii p[N];
vector <int> a[N];
queue <int> q;
struct edge{
    int x,y,w,idx;
    edge(int _x=0,int _y=0,int _w=0,int _idx=0){
        x=_x,y=_y,w=_w,idx=_idx;
    }
}e[N];
bool operator <(edge a,edge b){
    return a.w<b.w;
}
int root(int x){
    while (t[x]>0) x=t[x];
    return x;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,&w);
        e[i]=edge(x,y,w,i);
    }
    sort(e+1,e+m+1);
    memset(t,-1,sizeof(t));
    FOR(st,1,m){
        int en=st;
        while (en<m&&e[en+1].w==e[st].w) en++;
        FOR(i,st,en){
            p[i].X=root(e[i].x);
            p[i].Y=root(e[i].y);
            if (p[i].X!=p[i].Y) {
                a[p[i].X].push_back(i);
                a[p[i].Y].push_back(i);
                h[p[i].X]++,h[p[i].Y]++;
            }else ans[e[i].idx]=3;
        }
        FOR(i,st,en) if (p[i].X!=p[i].Y){
            if (h[p[i].X]==1) q.push(p[i].X);
            if (h[p[i].Y]==1) q.push(p[i].Y);
        }
        while (!q.empty()){
            int cx=q.front();q.pop();
            if (!h[cx]) continue;
            for(auto i:a[cx]) if (!ans[e[i].idx]){
                h[p[i].X]--,h[p[i].Y]--;
                ans[e[i].idx]=2;
                if (h[p[i].X]==1) q.push(p[i].X);
                if (h[p[i].Y]==1) q.push(p[i].Y);
            }
        }
        FOR(i,st,en) if (p[i].X!=p[i].Y){
            a[p[i].X].pop_back();
            a[p[i].Y].pop_back();
            if (!ans[e[i].idx]) ans[e[i].idx]=1;
            int rx=root(e[i].x),ry=root(e[i].y);
            if (rx!=ry){
                if (t[rx]<t[ry]) t[rx]+=t[ry],t[ry]=rx;
                else t[ry]+=t[rx],t[rx]=ry;
            }
        }
        st=en;
    }
    FOR(i,1,m) if (ans[i]==1) printf("at least one\n");
    else if (ans[i]==3) printf("none\n");
    else printf("any\n");
}