#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

ll dp[600][6000];
int num[101010],f[101010];
int main(){
    int n,k;
    cin>>n>>k;
    rep(i,n*k){
        int x;
        cin>>x;
        num[x]++;
    }
    rep(i,n){
        int y;
        cin>>y;
        f[y]++;
    }
    ll h[k+1];
    rep(i,k)cin>>h[i+1];
    h[0]=0;
    rep(i,k+1)dp[1][i]=h[i];
    rep(i,n-1)rep(j,k*(i+1)+1){
        rep(l,k+1)dp[i+2][j+l]=max(dp[i+1][j]+h[l],dp[i+2][j+l]);
    }
    rep(i,n+1)rep(j,5555)dp[i][j+1]=max(dp[i][j],dp[i][j+1]);
    ll ans=0;
    rep(i,101010){
        ans+=dp[f[i]][num[i]];
    }
    cout<<ans<<endl;
    return 0;
}