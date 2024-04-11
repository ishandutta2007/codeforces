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
#define WRONG {printf("IMPOSSIBLE");exit(0);}

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

vector <int> a[N][2],ans;
int n,m,x,y,h[N],cur=0,nex=1,pos[N];
char s[10];
void DFS(int R,int x){
    h[x]=3;
    FOR(j,0,1)
        for(auto i:a[x][j]){
            if (h[i]>=2) WRONG;
            h[i]=1+j;
        }
//    printf("%d %d %d\n",x,nex,R);
//    FOR(i,1,n) printf("%d ",h[i]);ENDL;
    if (!a[x][0].empty()&&nex<a[x][0].back()) DFS(a[x][0].back(),++nex);
    for(auto i:a[x][0]) if (h[i]!=3) WRONG;
    for(auto i:a[x][1]) {
        if (h[i]==3) WRONG;
        h[i]=1;
    }
//    printf("%d %d %d\n",x,nex,R);
//    FOR(i,1,n) printf("%d ",h[i]);ENDL;
    ans.push_back(x);
    if (!a[x][1].empty()) R=max(R,a[x][1].back());
    if (nex<R) DFS(R,++nex);
    for(auto i:a[x][1]) if (h[i]!=3) WRONG;
}
void solve(){
    h[n+1]=2;
    DFS(n,1);
    for(auto i:ans) printf("%d ",i);
}
int main(){
//    INPUT;
    scanf("%d%d\n",&n,&m);
    while (m--){
        scanf("%d%d%s",&x,&y,s);
//        printf("%d %d %s\n",x,y,s);
        a[x][s[0]=='R'].push_back(y);
    }
    FOR(i,1,n)
        FOR(j,0,1) {
            sort(a[i][j].begin(),a[i][j].end());
            a[i][j].resize(unique(a[i][j].begin(),a[i][j].end())-a[i][j].begin());
        }
    solve();
}