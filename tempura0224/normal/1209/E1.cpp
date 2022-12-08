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
        int n,m;
        cin>>n>>m;
        vector<int> ma(m+3);
        vector<vector<int>> a(n,vector<int>(m+3));
        rep(i,n){
            rep(j,m){
                cin>>a[i][j];
                ma[j]=max(ma[j],a[i][j]);
            }
        }
        vector<int> ord(m+3);
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](int p,int q){
            return ma[p]>ma[q];
        });
        if(ord.size()>4)ord.resize(4);
        int ans = 0;
        rep(i1,n)rep(i2,n)rep(i3,n)rep(i4,n){
            int res = 0;
            rep(j,n)res += max({a[(j+i1)%n][ord[0]],a[(j+i2)%n][ord[1]],a[(j+i3)%n][ord[2]],a[(j+i4)%n][ord[3]],});
            ans = max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}