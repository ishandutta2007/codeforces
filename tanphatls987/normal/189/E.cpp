#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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

int n,m,k,st,en,f[N],vol[N];
vector <int> v[N];
priority_queue <ii> q;
bool minimize(int &x,int y){
    if (x>y) x=y;else return 0;
    return 1;
}
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    int x,y;
    while (k--){
        scanf("%d",&x);
        vol[x]=1;
    }
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d%d",&st,&en);
}

bool check(int len){
    FOR(i,1,n) f[i]=len+1;
    f[st]=0;
    q.push(ii(0,st));
//    printf("%d\n",len);
    while (!q.empty()){
        int cw=-q.top().X,cx=q.top().Y;
        q.pop();
        if (cw>f[cx]) continue;
//        printf("%d %d\n",cx,cw);
        if (vol[cx]) f[cx]=0;
        if (f[cx]==len) continue;
        for(auto y:v[cx]) if (minimize(f[y],f[cx]+1)) q.push(ii(-f[y],y));
    }
//    printf("%d\n",len);
//    FOR(i,1,n) printf("%d ",f[i]);ENDL;
    return f[en]<=len;
}
int main(){
    prepare();
    int L=1,R=n;
    while (L<=R){
        int M=(L+R)>>1;
        if (check(M)) R=M-1;
        else L=M+1;
    }
    cout<<((L<=n)?L:-1);
}