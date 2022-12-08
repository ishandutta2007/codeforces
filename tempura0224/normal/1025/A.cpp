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
    if(n==1){
        cout<<"Yes"<<endl;
        return 0;
    }
    string s;cin>>s;
    map<char,int> mp;
    rep(i,n)mp[s[i]]++;
    bool ok=false;
    for(char c='a';c<='z';c++)if(mp[c]>=2)ok=true;
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}