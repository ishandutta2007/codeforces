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
    ll x;
    cin>>x;
    int m=2000-x%500;
    int k=m-500;
    int sum=(x+m)/500;
    int a[m];
    rep(i,m-k-1)a[i]=0;
    a[m-k-1]=-1;
    rep(i,k){
        if(sum>1e6){
            a[m-k+i]=1e6;
            sum-=1e6;
        }
        else {
            a[m-k+i]=sum;
            sum-=a[m-k+i];
        }
    }
    cout<<m<<endl;
    rep(i,m){
        cout<<a[i]<<" ";
    }

    return 0;
}