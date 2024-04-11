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
    int r,c;
    cin>>r>>c;
    if(r==1&&c==1){
        cout<<0<<endl;
        return 0;
    }
    if(r==1){
        rep(i,c)cout<<i+2<<" ";
        cout<<endl;
        return 0;
    }
    if(c==1){
        rep(i,r){
            cout<<i+2<<endl;
        }
        return 0;
    }
    vector<int> a(r), b(c);
    rep(i,r)a[i]=i+1;
    rep(i,c)b[i]=i+1+r;
    rep(i,r){
        rep(j,c)cout<<a[i]*b[j]<<" ";
        cout<<endl;
    }
    return 0;
}