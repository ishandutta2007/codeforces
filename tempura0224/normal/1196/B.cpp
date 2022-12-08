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
    int q;
    cin>>q;
    while(q--){
        int n,k;
        scanf("%d%d",&n,&k);
        vector<int> odd;
        rep(i,n){
            int x;
            cin>>x;
            if(x%2)odd.push_back(i+1);
        }
        int m = odd.size();
        if(m<k||(m-k)%2!=0){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            rep(i,k-1)cout<<odd[i]<<" ";
            cout<<n<<endl;
        }
    }
    return 0;
}