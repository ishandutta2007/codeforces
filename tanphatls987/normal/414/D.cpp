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
const int N=1e5+10;

int n,k,m,x,y,g[N],lv[N],depth;
vector <int> v[N];
queue <int> q;
bool check(int M){
//    printf("%d\n",M);
    ll sum=0,cost=1LL*M*depth;
    for(int R=depth,L=depth+1;R>0;R--){
        while (L>1&&sum+g[L-1]<M){
            sum+=g[--L];
            cost-=1LL*g[L]*L;
        }
        if (L>1&&cost-(M-sum)*(L-1)<=m) return 1;
//        printf("%d %d %lld %lld %lld\n",L,R,sum,cost,cost-(M-sum)*(L-1));
        cost+=1LL*g[R]*R-M;
        sum-=g[R];
    }
    return 0;
}
int main(){
//    INPUT;
    scanf("%d%d%d",&n,&k,&m);
    FOR(i,2,n){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    q.push(1);
    lv[1]=1;
    depth=0;
    while (!q.empty()){
        int x=q.front();q.pop();
        g[lv[x]-1]++;
        depth=max(depth,lv[x]-1);
        for(auto y:v[x]) if (!lv[y]){
            lv[y]=lv[x]+1;
            q.push(y);
        }
    }
//    FOR(i,1,depth) printf("%d ",g[i]);ENDL;
    int L=0,R=min(n-1,k);
    while (L<=R){
        int M=(L+R)>>1;
        if (check(M)) L=M+1;
        else R=M-1;
    }
    cout<<R;
}