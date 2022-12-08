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
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    rep(i,n){
        if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o')s[i]='a';
        else s[i]='b';
    }
    rep(i,m){
        if(t[i]=='a'||t[i]=='i'||t[i]=='u'||t[i]=='e'||t[i]=='o')t[i]='a';
        else t[i]='b';
    }
    if(s==t)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}