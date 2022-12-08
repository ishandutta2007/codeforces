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
    vector<int> a(n);
    rep(i,n-1)cin>>a[i];
    vector<int> used(n+1);
    int r = a[0];
    used[r]=1;
    a[n-1]=r;
    int ma = n;
    vector<int> b(n-1);
    rep(i,n-1){
        if(used[a[i+1]]){
            while(used[ma])--ma;
            used[ma]=1;
            b[i]=ma;
        }
        else {
            used[a[i+1]]=1;
            b[i]=a[i+1];
        }
    }
    cout<<r<<endl;
    rep(i,n-1)cout<<a[i]<<" "<<b[i]<<'\n';
    return 0;
}