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
    int a[n];
    bool odd=false,even=false;
    rep(i,n){
        scanf("%d",&a[i]);
        if(a[i]%2)odd=true;
        else even=true;
    }
    if(odd&&even)sort(a,a+n);
    rep(i,n){
        printf("%d ",a[i]);
    }
    cout<<endl;
    return 0;
}