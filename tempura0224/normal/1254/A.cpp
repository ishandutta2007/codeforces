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

void solve(){
    int r,c,k;
    cin>>r>>c>>k;
    string s[r];
    rep(i,r)cin>>s[i];
    int sum = 0;
    rep(i,r)rep(j,c)sum += s[i][j]=='R';
    vector<int> ans(k);
    rep(i,k)ans[i]=sum/k + ((sum%k)>i);
    int cur = 0;
    vector<vector<int>> res(r,vector<int>(c));
    rep(i,r){
        if(i%2==0)reverse(s[i].begin(),s[i].end());
        rep(j,c){
            if(s[i][j]=='R' && ans[cur]==0)cur++;
            if(s[i][j]=='R')--ans[cur];
            res[i][j]=cur;
        }
    }
    rep(i,r){
        if(i%2==0)reverse(res[i].begin(),res[i].end());
        rep(j,c){
            if(0<=res[i][j]&res[i][j]<26)cout<<char('A'+res[i][j]);
            if(26<=res[i][j]&res[i][j]<52)cout<<char('a'+res[i][j]-26);
            if(52<=res[i][j]&res[i][j]<63)cout<<char('0'+res[i][j]-52);
        }
        cout<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}