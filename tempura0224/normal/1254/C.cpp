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
    int mi = 2;
    REP(i,3,n+1){
        cout<<2<<" "<<1<<" "<<mi<<" "<<i<<endl;
        int x;
        cin>>x;
        if(x<0)mi=i;
    }
    vector<ll> a(n+1);
    REP(i,2,n+1){
        if(i==mi)continue;
        cout<<1<<" "<<1<<" "<<mi<<" "<<i<<endl;
        cin>>a[i];
    }
    vector<int> ord(n+1);
    rep(i,n+1)ord[i]=i;
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return a[x]>a[y];
    });
    deque<int> ans;
    ans.push_back(ord[0]);
    REP(i,1,n-2){
        cout<<2<<" "<<1<<" "<<ord[0]<<" "<<ord[i]<<endl;
        int x;cin>>x;
        if(x>0)ans.push_back(ord[i]);
        else ans.push_front(ord[i]);
    }
    cout<<"0 1 "<<mi;
    rep(i,n-2)cout<<" "<<ans[i];
    cout<<endl;

    return 0;
}