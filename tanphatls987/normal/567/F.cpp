#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
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
const int N=80;
const string sign[5]={"<","<=","=",">=",">"};

int n,m;
ll f[N][N];
vector <ii> a[N];
bool check(int sel1,int sel2,int L,int R){
//    printf("%d %d %d %d")
    FOR(phase,0,1){
        for(auto i:a[sel1]){
//            printf("%d %d %d %d\n",sel1,sel2,i.X,i.Y);
            if (i.X==sel2&&(i.Y<1||i.Y>3)) return 0;
            if (i.X>=L&&i.X<=R&&i.Y>1) return 0;
        }
        swap(sel1,sel2);
    }
    return 1;
}
ll solve(){
//    cout<<check(2,3,0,0)<<'\n';
    REP(i,1,n<<1) f[i][i+1]=check(i,i+1,0,0);
    FOR(len,2,n)
        FOR(st,0,(n-len)<<1){
            if (check(st+1,st+2,st+3,st+len*2)) f[st+1][st+len*2]+=f[st+3][st+len*2];
            if (check(st+1,st+len*2,st+2,st+len*2-1)) f[st+1][st+len*2]+=f[st+2][st+len*2-1];
            if (check(st+len*2,st+len*2-1,st+1,st+len*2-2)) f[st+1][st+len*2]+=f[st+1][st+len*2-2];
        }
//    FOR(i,1,n<<1)
//        FOR(j,i+1,n<<1) printf("%d %d %lld\n",i,j,f[i][j]);
    return f[1][n<<1];
}
int main(){
    cin>>n>>m;
    while (m--){
        int x,y,re=0;
        string s;
        cin>>x>>s>>y;
        while (s!=sign[re]) re++;
        a[x].push_back(ii(y,re));
        a[y].push_back(ii(x,4-re));
//        printf("->%d %d %d\n%d %d %d\n",x,y,re,y,x,4-re);
    }
    cout<<solve();
}