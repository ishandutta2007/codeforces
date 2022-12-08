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
    int n;
    cin>>n;
    string s;
    cin>>s;
    string RGB[6]={"RGB","RBG","BRG","BGR","GRB","GBR"};
    int ans=inf,idx=-1;
    rep(i,6){
        int cnt=0;
        rep(j,n){
            if(s[j]!=RGB[i][j%3])++cnt;
        }
        if(cnt<ans)ans=cnt,idx=i;
    }
    cout<<ans<<endl;
    rep(i,n){
        cout<<RGB[idx][i%3];
    }
    return 0;
}