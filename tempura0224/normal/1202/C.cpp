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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        vector<ll> yoko(1,0), tate(1,0);
        int ct = 0, cy = 0;
        rep(i,n){
            if(s[i]=='W')tate.push_back(++ct);
            if(s[i]=='S')tate.push_back(--ct);
            if(s[i]=='A')yoko.push_back(++cy);
            if(s[i]=='D')yoko.push_back(--cy);
        }
        ll ans[2][2];
        rep(k,2){
            int m = yoko.size();
            vector<ll> fa(m+1,-inf),fi(m+1,inf),ba(m+1,-inf),bi(m+1,inf);
            rep(i,m){
                fa[i+1]=max(fa[i],yoko[i]);
                fi[i+1]=min(fi[i],yoko[i]);
                ba[m-i-1]=max(ba[m-i],yoko[m-i-1]);
                bi[m-i-1]=min(bi[m-i],yoko[m-i-1]);
            }
            ans[k][0]=fa[m]-fi[m]+1;
            ans[k][1]=inf;
            rep(i,m){
                ans[k][1]=min(ans[k][1],max({yoko[i]+1,fa[i+1],ba[i+1]+1})-min({yoko[i]+1,fi[i+1],bi[i+1]+1})+1);
                ans[k][1]=min(ans[k][1],max({yoko[i]+1,fa[i+1],ba[i+1]-1})-min({yoko[i]+1,fi[i+1],bi[i+1]-1})+1);
            }
            yoko.swap(tate);
        }
        cout<<min({ans[0][0]*ans[1][0],ans[0][1]*ans[1][0],ans[0][0]*ans[1][1]})<<"\n";
    }
    return 0;
}