#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

bool ok[3000][3000];
int main(){
    int n,k;
    cin>>n>>k;
    string s[n];
    rep(i,n)cin>>s[i];
    int dist[n+1][n+1];
    rep(i,n+1)rep(j,n+1)dist[i][j]=inf;
    dist[0][0]=(s[0][0]!='a');
    rep(i,n)rep(j,n){
        if(j<n-1&&s[i][j+1]=='a')dist[i][j+1]=min(dist[i][j],dist[i][j+1]);
        else dist[i][j+1]=min(dist[i][j]+1,dist[i][j+1]);
        if(i<n-1&&s[i+1][j]=='a')dist[i+1][j]=min(dist[i][j],dist[i+1][j]);
        else dist[i+1][j]=min(dist[i][j]+1,dist[i+1][j]);
    }
    rep(i,n)rep(j,n){
        if(dist[i][j]<=k)s[i][j]='a';
    }
    string ans="";
    ok[0][0]=true;
    rep(i,2*n-1){
        char ret='z';
        if(i<=n-1){
            rep(j,i+1){
                if(ok[j][i-j])ret=min(ret,s[j][i-j]);
            }
            ans+=ret;
            rep(j,i+1){
                if(ok[j][i-j]&&s[j][i-j]==ret){
                    ok[j+1][i-j]=true;
                    ok[j][i-j+1]=true;
                }
            }
        }
        else {
            REP(j,i-n+1,n){
                if(ok[j][i-j])ret=min(ret,s[j][i-j]);
            }
            ans+=ret;
            REP(j,i-n+1,n){
                if(ok[j][i-j]&&s[j][i-j]==ret){
                    ok[j+1][i-j]=true;
                    ok[j][i-j+1]=true;
                }
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}