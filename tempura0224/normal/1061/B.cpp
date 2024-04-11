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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,m;
    cin>>n>>m;
    ll a[n+1];
    a[n]=0;
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    ll ret=0;
    int ma=a[0];
    rep(i,n){
        a[i+1]=min(a[i],a[i+1]);
        if(a[i]==a[i+1]){
            a[i+1]=max(1LL,a[i+1]-1);
        }
        ret+=max(a[i]-a[i+1],1LL);
    }
    cout<<sum-ret<<endl;
    return 0;
}