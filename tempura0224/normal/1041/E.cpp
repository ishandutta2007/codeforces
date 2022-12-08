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
    int n;cin>>n;
    vector<int> v;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        if(y!=n){
            cout<<"NO"<<endl;
            return 0;
        }
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    rep(i,n-1){
        if(v[i]<=i){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    int lb=1;
    bool used[n];
    rep(i,n)used[i]=false;
    vector<int> ans;
    rep(i,n-1){
        if(!used[v[i]]){
            ans.push_back(v[i]);
            used[v[i]]=true;
        }
        else {
            while(used[lb])++lb;
            ans.push_back(lb);
            used[lb]=true;
        }
    }
    ans.push_back(n);
    rep(i,n-1){
        printf("%d %d\n",ans[i],ans[i+1]);
    }
    return 0;
}