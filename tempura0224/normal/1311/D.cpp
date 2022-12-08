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
    int t;cin>>t;
    vector<int> v[20001];
    for(int i=1;i<=20000;i++){
        for(int j=i;j<=20000;j+=i){
            v[j].push_back(i);
        }
    }
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int A=-1,B=-1,C=-1, ans = 30000;
        for(int nc = 1;nc<=20000;++nc){
            if(ans<abs(c-nc))continue;
            for(auto e:v[nc]){
                for(auto f:v[e]){
                    int res = abs(c-nc)+abs(b-e)+abs(a-f);
                    if(res<ans){
                        ans=res;
                        A = f;
                        B = e;
                        C = nc;
                    }
                }
            }
        }
        cout<<ans<<endl;
        cout<<A<<" "<<B<<" "<<C<<endl;
    }
    return 0;
}