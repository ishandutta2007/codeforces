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
    priority_queue<int,vector<int>, greater<int>> que;
    int n;
    cin>>n;
    rep(i,n){
        int x;
        cin>>x;
        que.push(x);
    }
    int ans=0;
    while(que.size()){
        if(que.top()>ans)++ans;
        que.pop();

    }
    cout<<ans<<endl;
    return 0;
}