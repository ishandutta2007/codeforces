#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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

int n,m,x,y,type,h[N];
vector <ii> v[N];
queue <int> q;
int main(){
    cin>>n>>m;
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,&type);
        v[x].push_back(ii(type^1,y));
        v[y].push_back(ii(type^1,x));
    }
    int ans=1;
    memset(h,-1,sizeof(h));
    FOR(i,1,n) if (h[i]==-1){
        h[i]=0;
        q.push(i);
        while (!q.empty()){
            int x=q.front();q.pop();
            for(auto j:v[x]){
                int y=j.Y,ns=h[x]^j.X;
                if (h[y]==-1){
                    h[y]=ns;
                    q.push(y);
                }else if (h[y]!=ns){
                    printf("0");
                    return 0;
                }
            }
        }
        if (i!=1) ans=ans*2%MOD;
    }
    cout<<ans;
}