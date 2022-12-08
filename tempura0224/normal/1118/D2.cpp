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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    ll n,m;
    cin>>n>>m;
    ll a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    ll sum=0;
    rep(i,n-1)a[i+1]+=a[i];
    if(a[n-1]<m){
        cout<<-1<<endl;
        return 0;
    }
    int ok=n,ng=0;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        vector<ll> res(n);
        ll loss=0;
        rep(i,n){
            loss+=i/mid;
            res[i]=a[i]-loss;
        }
        ll ret=*max_element(res.begin(),res.end());
        if(ret>=m)ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
    return 0;
}