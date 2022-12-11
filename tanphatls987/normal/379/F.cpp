#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e6+10,M=20;

int p[N][20],lv[N],n,m,a[N];
vector <int> v[N];
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    for(int i=0,v=lv[x]-lv[y];v;i++,v>>=1) if (v&1) x=p[x][i];
    if (x==y) return x;
    FORD(i,int(log2(lv[x])),0) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
int dist(int x,int y){
    int z=LCA(x,y);
    return lv[x]+lv[y]-2*lv[z];
}
void prepare(){
    n=4;
    FOR(i,2,4) v[1].push_back(i);
    scanf("%d",&m);
    FOR(i,1,m){
        scanf("%d",a+i);
        FOR(j,0,1) v[a[i]].push_back(++n);
    }
    lv[1]=1;
    FOR(x,1,n)
        for(auto y:v[x]){
            lv[y]=lv[x]+1;
            p[y][0]=x;
        }
    REP(j,1,M)
        FOR(i,1,n) p[i][j]=p[p[i][j-1]][j-1];
}
int main(){
    prepare();
    int x=2,y=3;
    n=4;
    FOR(i,1,m){
        n+=2;
        int d1=dist(n,x),d2=dist(n,y),cur=dist(x,y);
        if (max(d1,d2)>cur){
            if (d1>d2) y=n;
            else x=n;
        }
        printf("%d\n",dist(x,y));
    }
}