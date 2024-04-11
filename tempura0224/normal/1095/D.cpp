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
    if(n==3){
        cout<<"1 2 3"<<endl;
        return 0;
    }
    int a[n+1][2];
    rep(i,n)cin>>a[i+1][0]>>a[i+1][1];
    int idx=1;
    rep(i,n){
        printf("%d ",idx);
        int nx1=a[idx][0],nx2=a[idx][1];
        if(a[nx1][0]==nx2||a[nx1][1]==nx2){
            idx=nx1;
        }
        else idx=nx2;
    }
    return 0;
}