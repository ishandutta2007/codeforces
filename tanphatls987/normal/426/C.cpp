#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=2e2+10,M=20;

int h[N][N][M],n,m,a[N];
multiset <int> s;
int solve(){
    int ans=*max_element(a+1,a+n+1);
    if (ans<0) return ans;
    FOR(i,1,m) h[0][n+1][i]=-inf;
    FOR(i,0,n)
        FORD(j,n+(i>0),i+1)
            FOR(k,1,m) {
                if (i>0) h[i][j][k]=max(h[i][j][k],max(h[i-1][j][k-1]+a[i],h[i-1][j][k]));
                if (j<=n) h[i][j][k]=max(h[i][j][k],max(h[i][j+1][k-1]+a[j],h[i][j+1][k]));
//                printf("%d %d %d %d\n",i,j,k,h[i][j][k]);
            }
    FOR(st,1,n){
        s.clear();
        int sum=0;
        FOR(en,st,n){
            s.insert(a[en]);
            sum+=a[en];
            int c=0,cur=sum;
            ans=max(ans,sum);
            for(auto i=s.begin();i!=s.end();i++){
                c++;
                if (c>m) break;
                cur-=*i;
                ans=max(ans,cur+h[st-1][en+1][c]);
//                printf("%d %d %d %d %d\n",st,en,c,cur,h[st-1][en+1][c]);
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    cout<<solve();

}