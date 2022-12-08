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
    int a[n][n];
    rep(i,n)rep(j,n/4){
        a[i][4*j]=4*n*j+4*i;
        a[i][4*j+1]=4*n*j+4*i+1;
        a[i][4*j+2]=4*n*j+4*i+2;
        a[i][4*j+3]=4*n*j+4*i+3;
    }
    bool ok=false;
    rep(i,n){
        int x = 0;
        rep(j,n)x^=a[i][j];
        assert(x==0);
    }
    rep(i,n){
        int x = 0;
        rep(j,n)x^=a[j][i];
        assert(x==0);
    }
    rep(i,n){
        rep(j,n)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}