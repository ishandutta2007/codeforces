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
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    cout<<n+1<<endl;
    for(int i=n-1;i>=0;--i){
        int res=(i-a[i]%n+n)%n;
        printf("1 %d %d\n",i+1,res);
        rep(j,i+1)a[j]+=res;
    }
    printf("2 %d %d\n",n,n);
    return 0;
}