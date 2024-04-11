#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=5e2+10;
const char ch[3]={'b','a','c'};

int n,v[N][N],ans[N],q[N];
void prepare(){
    int m,x,y;
    scanf("%d%d",&n,&m);
    while (m--){
        scanf("%d%d",&x,&y);
        v[x][y]=v[y][x]=1;
    }
}
int BFS(int st){
    q[1]=st;
    int top=1,bot=1;
    while (top<=bot){
        int x=q[top++];
        FOR(i,1,n) if (v[x][i]&&!ans[i]){
            ans[i]=ans[x];
            q[++bot]=i;
        }
    }
    return bot;
}
void solve(){
    FOR(i,1,n) if (count(v[i]+1,v[i]+n+1,1)==n-1) ans[i]=1;
    int n1=1;
    FOR(i,1,n) if (!ans[i]){
        ans[i]=++n1;
        int n2=BFS(i);
        FOR(i1,1,n2)
            FOR(j1,i1+1,n2) if (!v[q[i1]][q[j1]]){
                printf("No");
                return;
            }
    }
    if (n1>3){
        printf("No");
        return;
    }
    printf("Yes\n");
    FOR(i,1,n) printf("%c",ch[ans[i]-1]);
}
int main(){
    prepare();
    solve();
}