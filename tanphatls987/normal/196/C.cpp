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
const int N=1550;

int q[N],p[N],sub[N],ans[N],piv,n;
ii cord[N];
vector <int> v[N];
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
ll operator *(ii a,ii b){
    return 1LL*a.X*b.Y-1LL*a.Y*b.X;
}
bool comp(int x,int y){
    return (cord[x]-cord[piv])*(cord[y]-cord[piv])>0;
}
bool operator <(ii a,ii b){
    return (a.Y==b.Y)?a.X<b.X:a.Y<b.Y;
}
void BFS(){
    q[1]=1;
    sub[1]=1;
    int top=1,bot=1;
    while (top<=bot){
        int x=q[top++],m1=v[x].size();
        REP(i,0,m1){
            int y=v[x][i];
            if (!sub[y]){
                sub[y]=1;
                q[++bot]=y;
            }else {
                swap(v[x][i--],v[x][--m1]);
                v[x].pop_back();
            }
        }
    }
    FORD(i,n,1)
        for(auto x:v[q[i]]) sub[q[i]]+=sub[x];
}
void build(int root,int st){
    int en=st+sub[root];
    int sel=st;
    REP(i,st,en) if (cord[p[i]]<cord[p[sel]]) sel=i;
    swap(p[sel],p[st]);
    piv=p[st];
    ans[p[st++]]=root;
    sort(p+st,p+en,comp);
    for(auto x:v[root]){
        build(x,st);
        st+=sub[x];
    }
}
int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    FOR(i,1,n) scanf("%d%d",&cord[i].X,&cord[i].Y);
    BFS();
//    FOR(i,1,n) cout<<sub[i]<<" \n"[i==n];
    FOR(i,1,n) p[i]=i;
    build(1,1);
    FOR(i,1,n) printf("%d ",ans[i]);
}