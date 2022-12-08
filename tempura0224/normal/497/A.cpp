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
    int n,m;
    cin>>n>>m;
    string s[n];
    rep(i,n)cin>>s[i];
    int ans = 0;
    vector<int> a(n);
    string t[n];
    rep(j,m){
        bool ok=true;
        rep(i,n-1){
            if(a[i]==a[i+1]&&s[i][j]>s[i+1][j])ok=false;
        }
        if(!ok)++ans;
        else {
            rep(i,n)t[i]+=s[i][j];
            rep(i,n-1){
                if(t[i]==t[i+1])a[i+1]=a[i];
                else a[i+1]=i+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}