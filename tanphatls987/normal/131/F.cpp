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
const int N=5e2+10;
const int dx[5]={0,-1,0,1,0},dy[5]={0,1,1,1,2};

int a[N][N],f[N][N]={0},n,m,k;
char s[N];
ll solve(){
    ll ans=0;
    FOR(up,1,n)
        FOR(down,up,n)
            for(int L=1,R=0,sum=0;L<=m;L++){
                while (R<m&&sum<k){
                    R++;
                    if (R>2) sum+=f[down-1][R-2]-f[up][R-2];
                }
                //printf("%d %d %d %d %d\n",up,down,L,R,sum);
                if (sum>=k) ans+=m-R+1;
                else break;
                sum-=f[down-1][L]-f[up][L];
            }
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n){
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=s[j-1]-'0';
    }
    FOR(i,1,n)
        FOR(j,1,m){
            FOR(k,0,4) f[i][j]+=a[i+dx[k]][j+dy[k]];
            f[i][j]=(f[i][j]==5);
        }

    FOR(j,1,m)
        FOR(i,1,n) f[i][j]+=f[i-1][j];
//    FOR(i,1,n){
//        FOR(j,1,m) printf("%d ",f[i][j]);ENDL;
//    }
    cout<<solve();
}