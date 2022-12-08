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
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int h,w,k;
    cin>>h>>k;
    w=h;
    string s[h];
    rep(i,h)cin>>s[i];
    vector<vector<int>> a(h+1,vector<int>(w+1));
    rep(i,h)rep(j,w)a[i+1][j+1]=(s[i][j]=='B');
    rep(i,h)rep(j,w+1){
        a[i+1][j]+=a[i][j];
    } 
    rep(i,h+1)rep(j,w){
        a[i][j+1]+=a[i][j];
    }
    int ans = 0;
    rep(i,h)if(a[i+1][w]-a[i][w]==0)++ans;
    rep(j,w)if(a[h][j+1]-a[h][j]==0)++ans;
    vector<vector<int>> ans1(h+1,vector<int>(w+1)),ans2(h+1,vector<int>(w+1));
    rep(i,h)rep(j,w-k+1){
        if(a[i+1][w]-a[i][w]==0)continue;
        if(a[i+1][j]-a[i][j]==0&&a[i+1][w]-a[i][w]-a[i+1][j+k]+a[i][j+k]==0)++ans1[i+1][j+1];
    }
    
    rep(i,h-k+1)rep(j,w){
        if(a[h][j+1]-a[h][j]==0)continue;
        if(a[i][j+1]-a[i][j]==0&&a[h][j+1]-a[h][j]-a[i+k][j+1]+a[i+k][j]==0)++ans2[i+1][j+1];
    }
    rep(i,h)rep(j,w+1)ans1[i+1][j]+=ans1[i][j];
    rep(i,h+1)rep(j,w)ans2[i][j+1]+=ans2[i][j];
    int ma = 0;
    rep(i,h-k+1)rep(j,w-k+1){
        ma = max(ma,ans2[i+1][j+k]-ans2[i+1][j]+ans1[i+k][j+1]-ans1[i][j+1]);
    }
    cout<<ans+ma<<endl;
    return 0;
}