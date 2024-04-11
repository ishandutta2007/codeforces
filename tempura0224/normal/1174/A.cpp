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
    int n;
    cin>>n;
    n*=2;
    int a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    int sum=0;
    rep(i,n){
        if(i<n/2)sum+=a[i];
        else sum-=a[i];
    }
    if(sum==0)cout<<-1<<endl;
    else{
        rep(i,n)cout<<a[i]<<" ";
        cout<<endl;
    } 
    return 0;
}