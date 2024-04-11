#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=1e2+5;

int b[N]={0},a[N][N],n,m,f[N][N]={0};

char s[N];
void add(int x,int v){
    while (x<=m){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=(s[j-1]=='B')?-1:1;
    }
    int ans=0;
    FORD(i,n,1)
        FORD(j,m,1){
            int v=get(j);
            //printf("%d %d %d\n",i,j,v);
            if (v!=a[i][j]){
                ans++;
                add(1,a[i][j]-v);
                add(j+1,v-a[i][j]);
            }
        }
    cout<<ans;
}