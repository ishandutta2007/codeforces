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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    string s[h];
    rep(i,h)cin>>s[i];
    vector<vector<int>> a(h+1,vector<int>(w+1));
    rep(i,h)rep(j,w)a[i+1][j+1]=s[i][j]=='.';
    rep(i,h)rep(j,w)a[i+1][j+1]+=a[i+1][j];
    rep(i,h)rep(j,w)a[i+1][j+1]+=a[i][j+1];
    int ok = 0, ng = (min(h,w)+1)/2+1;
    vector<vector<int>> b(h+1,vector<int>(w+1));
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        int m = 2*mid+1;
        rep(i,h+1)rep(j,w+1)b[i][j]=0;
        rep(i,h){
            if(i+m>h)break;
            rep(j,w){
                if(j+m>w)break;
                if(a[i][j]+a[i+m][j+m]==a[i][j+m]+a[i+m][j]){
                    ++b[i][j];++b[i+m][j+m];
                    --b[i+m][j];--b[i][j+m];
                }
            }
        }
        rep(i,h+1)rep(j,w)b[i][j+1]+=b[i][j];
        rep(i,h)rep(j,w+1)b[i+1][j]+=b[i][j];
        bool can = true;
        rep(i,h){
            if(!can)break;
            rep(j,w){
                if(s[i][j]=='X' && b[i][j]==0){
                    can=false;
                    break;
                }
            }
        }
        if(can)ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
    vector<string> ans(h);
    rep(i,h)rep(j,w)ans[i]+='.';
    int m = 2*ok+1;
    rep(i,h)rep(j,w){
        if(i+m<=h&&j+m<=w&&a[i][j]+a[i+m][j+m]==a[i][j+m]+a[i+m][j]){
            ans[i+ok][j+ok]='X';
        }
    }
    rep(i,h){
        cout<<ans[i]<<'\n';
    }
    return 0;
}