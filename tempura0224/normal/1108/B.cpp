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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

bool used[101010];
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    cout<<a[0]<<" ";
    rep(i,n){
        if(!used[a[i]]&&a[0]%a[i]==0){
            used[a[i]]=1;
        }
        else {
            cout<<a[i]<<" ";
            break;
        }
    }
    return 0;
}