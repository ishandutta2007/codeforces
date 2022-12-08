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


void ans(bool f){
    if(f)cout<<"sjfnb"<<endl;
    else cout<<"cslnb"<<endl;
    exit(0);
}
int main(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    if(n==1){
        ans(a[0]%2==1);
    }
    rep(i,n-2){
        if(a[i]==a[i+2]){
            cout<<"cslnb"<<endl;
            return 0;
        }
    }
    int cnt2=0;
    rep(i,n-1){
        if(a[i]==a[i+1])cnt2++;
    }
    if(cnt2>=2){
        cout<<"cslnb"<<endl;
        return 0;
    }
    rep(i,n-2){
        if(a[i]+1==a[i+1]&&a[i+1]==a[i+2]){
            cout<<"cslnb"<<endl;
            return 0;
        }
    }
    if(a[1]==0){
        cout<<"cslnb"<<endl;
        return 0;
    }
    ll sum = 0;
    rep(i,n){
        sum+=a[i]-i;
    }
    ans(sum%2==1);
    return 0;
}