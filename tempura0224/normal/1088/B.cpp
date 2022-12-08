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
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    n=a.size();
    rep(i,n-1)a[n-i-1]-=a[n-i-2];
    rep(i,m){
        if(i>=n)printf("0\n");
        else printf("%d\n",a[i]);
    }
    return 0;
}