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
const int MOD=1e9+7,BASE=1e5+3;
const int N=1e5+10;

int n,a[N],t[N];
ll pba[N],ha[N];
map <int,int> ma;
vector <int> pos[N];
class comp{
    public:bool operator()(ii a,ii b){
        if (a.X==b.X) return a.Y>b.Y;
        return a.X>b.X;
    };
};
priority_queue <ii,vector<ii>,comp> q;
int gethash(int x,int y){
    if (x>y) return 0;
    return (ha[y]+MOD-ha[x]*pba[y-x]%MOD)%MOD;
}

int main(){
    scanf("%d",&n);
    int top=0;
    FOR(i,1,n) {
        scanf("%d",a+i);
        if (!ma[a[i]]) ma[a[i]]=++top,t[top]=a[i];
        a[i]=ma[a[i]];
        pos[a[i]].push_back(i);
    }
    pba[0]=1;
    FOR(i,1,n) pba[i]=pba[i-1]*BASE%MOD;
    FOR(i,1,n) ha[i]=(ha[i-1]*BASE+a[i])%MOD;
    FOR(te,1,top){
        int m=pos[te].size();
        REP(i,0,m-1)
            REP(j,i+1,m){
                int x=pos[te][i],y=pos[te][i+1],len=y-x;
                if (y+len-1<=n&&gethash(x,y-1)==gethash(y,y+len-1)) q.push(ii(len,x));
            }
    }
    int L=0;
    while (!q.empty()){
        ii cur=q.top();q.pop();
        if (cur.Y<=L) continue;
        L=cur.Y+cur.X-1;
    }
    printf("%d\n",n-L);
    FOR(i,L+1,n) printf("%d ",t[a[i]]);
}