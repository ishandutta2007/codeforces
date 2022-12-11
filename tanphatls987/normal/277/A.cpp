#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=2e2+10;

int n,m,h[N],over=0;
queue <int> q;
vector <int> v[N];
void prepare(){
    scanf("%d%d",&n,&m);
    int m1,x;
    FOR(i,1,n){
        scanf("%d",&m1);
        over+=m1;
        while (m1--){
            scanf("%d",&x);
            v[i].push_back(n+x);
            v[n+x].push_back(i);
        }
    }
}
bool BFS(int st){
    q.push(st);
    h[st]=1;
    int c=0;
    while (!q.empty()){
        int x=q.front();q.pop();
        c+=x<=n;
        for(auto y:v[x]) if (!h[y]) h[y]=1,q.push(y);
    }
    return c;
}
int solve(){
    int ans=0;
    FOR(i,1,n+m) if (!h[i]) ans+=BFS(i);
    return ans-(over>0);
}
int main(){
    prepare();
    cout<<solve();
}