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

int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n==2&&s[0]>=s[1]){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<s[0]<<" ";
            cout<<s.substr(1)<<endl;
        }
    }
    return 0;
}