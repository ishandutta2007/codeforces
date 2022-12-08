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
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
int main(){
    int n;
    cin>>n;
    int x[n],y[n];
    rep(i,n)cin>>x[i]>>y[i];
    map<pair<int,int>,set<int>> mp;
    ll ans = 0, cnt = 0;
    rep(i,n)rep(j,i){
        // (x[i]-x[j])(y-y[j])-(y[i]-y[j])(x-x[j])=0;
        // -(y[i]-y[j]), (x[i]-x[j]), (x[j]y[i]-x[i]y[j])
        int a = -y[i]+y[j], b=x[i]-x[j], c=x[j]*y[i]-x[i]*y[j];
        if(a<0){
            a=-a;b=-b;c=-c;
        }
        if(a==0 && b<0){
            b=-b;c=-c;
        }
        int g = gcd(gcd(abs(a),abs(b)),abs(c));
        a/=g;b/=g;c/=g;
        auto& s = mp[{a,b}];
        if(!s.count(c)){
            ans += cnt - s.size();
            s.insert(c);
            ++cnt;
        }
    }
    cout<<ans<<endl;
    return 0;
}