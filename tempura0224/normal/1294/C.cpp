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
        vector<int> ans;
        for(int i=2;i*i<=n;++i){
            if(n%i==0){
                n/=i;
                ans.push_back(i);
            }
            if(ans.size()==2){
                ans.push_back(n);
                break;
            }
        }
        if(ans.size()<=2){
            cout<<"NO"<<endl;
        }
        else {
            bool ok=true;
            rep(i,3)if(ans[i]==1)ok=false;
            rep(i,3)rep(j,i)if(ans[i]==ans[j])ok=false;
            if(!ok)cout<<"NO"<<endl;
            else {
                cout<<"YES"<<endl;
                cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
            }
        }
    }
    return 0;
}