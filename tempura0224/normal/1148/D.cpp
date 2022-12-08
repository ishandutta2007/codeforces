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

using  P = pair<pair<int,int> ,int>;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> posi,nega;
    map<pair<int,int>,int> mp;
    rep(i,n){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<y)posi.emplace_back(x,y);
        else nega.emplace_back(x,y);
        mp[{x,y}]=i;
    }
    if(posi.size()>=nega.size()){
        cout<<posi.size()<<endl;
        sort(posi.begin(),posi.end(),[](auto x,auto y){
            return x.second>y.second;
        });
        for(auto p : posi){
            printf("%d ",mp[p]+1);
        }
    }
    else {
        cout<<nega.size()<<endl;
        sort(nega.begin(),nega.end(),[](auto x,auto y){
            return x.second<y.second;
        });
        for(auto p : nega){
            printf("%d ",mp[p]+1);
        }
    }
    return 0;
}