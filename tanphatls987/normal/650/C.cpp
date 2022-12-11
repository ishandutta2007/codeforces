#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e6+10;

int n,m,group[N],f[N];
ii p[N];
vector <int> v[N],a[N];
queue <int> q;
int nexthor(int x){
    if (x+m>=n*m) return -1;
    return x+m;
}
int nextver(int x){
    if ((x+1)%m==0) return -1;
    return x+1;
}
void BFS(int st){
    static int n1=0;
    group[st]=++n1;
    q.push(st);
    while (!q.empty()){
        int x=q.front();q.pop();
        for(auto y:v[x]) if (!group[y]){
            group[y]=group[x];
            q.push(y);
        }
    }
}
int DP(int x){
    if (f[x]!=-1) return f[x];
    f[x]=1;
    for(auto y:v[x]) f[x]=max(f[x],DP(y)+1);
    return f[x];
}
void prepare(){
    scanf("%d%d",&n,&m);
    REP(i,0,n) a[i].resize(m);
    REP(i,0,n)
        REP(j,0,m) scanf("%d",&a[i][j]);
    REP(i,0,n){
        REP(j,0,m) p[j]=ii(a[i][j],j);
        sort(p,p+m);
        REP(j,0,m-1) if (p[j].X==p[j+1].X){
//            cout<<i*m+p[j].Y<<" "<<i*m+p[j+1].Y<<'\n';
            v[i*m+p[j].Y].push_back(i*m+p[j+1].Y);
            v[i*m+p[j+1].Y].push_back(i*m+p[j].Y);
        }
    }
    REP(j,0,m){
        REP(i,0,n) p[i]=ii(a[i][j],i);
        sort(p,p+n);
        REP(i,0,n-1) if (p[i].X==p[i+1].X){
//            cout<<p[i].Y*m+j<<" "<<p[i+1].Y*m+j;
            v[p[i].Y*m+j].push_back(p[i+1].Y*m+j);
            v[p[i+1].Y*m+j].push_back(p[i].Y*m+j);
        }
    }
    REP(i,0,n*m) if (!group[i]) BFS(i);
//    REP(i,0,n)
//        REP(j,0,m) cout<<group[i*m+j]<<" \n"[j==m-1];
    REP(i,0,n*m) v[i].clear();
    REP(i,0,n){
        REP(j,0,m) p[j]=ii(a[i][j],j);
        sort(p,p+m);
        REP(j,0,m-1) if (p[j].X!=p[j+1].X){
//            cout<<group[i*m+p[j+1].Y]<<" "<<group[i*m+p[j].Y]<<'\n';
            v[group[i*m+p[j+1].Y]].push_back(group[i*m+p[j].Y]);
        }
    }
    REP(j,0,m){
        REP(i,0,n) p[i]=ii(a[i][j],i);
        sort(p,p+n);
        REP(i,0,n-1) if (p[i].X!=p[i+1].X){
//            cout<<group[p[i+1].Y*m+j]<<" "<<group[p[i].Y*m+j]<<'\n';
            v[group[p[i+1].Y*m+j]].push_back(group[p[i].Y*m+j]);
        }
    }
    memset(f,-1,sizeof(f));
    REP(i,0,n){
        REP(j,0,m) printf("%d ",DP(group[i*m+j]));
        ENDL;
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
//    solve();
}