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
const int N=1e2+10;

int n,m,h[N];
vector <ii> a[N];
queue <int> q;
bool BFS(int st){
    h[st]=0;
    q.push(st);
    while (!q.empty()){
        int x=q.front();q.pop();
        for(auto i:a[x]){
            if (h[i.X]!=-1){
                if ((h[i.X]^h[x])!=i.Y) return 0;
            }else{
                h[i.X]=h[x]^i.Y;
                q.push(i.X);
            }
        }
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x].push_back(ii(y,z^1));
        a[y].push_back(ii(x,z^1));
    }
    memset(h,-1,sizeof(h));
    FOR(i,1,n) if (h[i]==-1){
        if (!BFS(i)){
            printf("Impossible");
            return 0;
        }
    }
    printf("%d\n",count(h+1,h+n+1,1));
    FOR(i,1,n) if (h[i]==1) printf("%d ",i);
}