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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

void solve(){
    int n,m;
    cin>>n>>m;
    string s[n];
    rep(i,n)cin>>s[i];
    vector<pair<int,int>> ans1;
    vector<pair<int,int>> ans2;
    rep(i,n)rep(j,m){
        if(i+j==n+m-2)continue;
        int x=min(i,n-2), y=min(j,m-2);
        rep(k,2)rep(l,2){
            if(s[x+k][y+l]=='0')s[x+k][y+l]='1';
            else s[x+k][y+l]='0';
        }
        ans1.emplace_back(x,y);
    }
    int cnt = n*m-1;
    rep(i,n)rep(j,m)if(s[i][j]=='1')++cnt;
    if(cnt%2){
        rep(k,2)rep(l,2){
            if(s[n-1-k][m-1-l]=='0')s[n-1-k][m-1-l]='1';
            else s[n-1-k][m-1-l]='0';
        }
        ans1.emplace_back(n-2,m-2);
    }
    rep(i,n)rep(j,m){
        if(ans1.size()!=n*m&&i==n-1&&j==m-1)continue;
        if(s[i][j]=='1'){
            ans2.emplace_back(i,j);
            s[i][j]='0';
        } else if(j+1<m){
            ans2.emplace_back(i,j+1);
            if(s[i][j+1]=='0')s[i][j+1]='1';
            else s[i][j+1]='0';
        } else if(i+1<n){
            ans2.emplace_back(i+1,j);
            if(s[i+1][j]=='0')s[i+1][j]='1';
            else s[i+1][j]='0';
        } else {
            assert(false);
        }
    }
    cout<<ans1.size()<<endl;
    rep(t,ans1.size()){
        rep(j,2)rep(k,2){
            if(ans1[t].first+j!=ans2[t].first || ans1[t].second+k!=ans2[t].second){
                cout<<ans1[t].first+j+1<<" "<<ans1[t].second+k+1<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
    
    return 0;
}