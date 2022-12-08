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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s="1";
        vector<int> res;
        while(n){
            ll m = 1;
            while(m*(m-1)/2<=n)++m;
            --m;
            ll t = 1;
            n-=m*(m-1)/2*t;
            res.push_back(m);
        }
        reverse(res.begin(),res.end());
        int cur = 0;
        rep(i,res.size()){
            rep(j,res[i]-cur)s+='3';
            s+='7';
            cur = res[i];
        }
        assert(s.size()<=100000);
        cout<<s<<endl;
    }
    return 0;
}