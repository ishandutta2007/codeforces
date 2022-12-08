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
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
   int q;cin>>q;
   while(q--){
       int n;cin>>n;
       string s;cin>>s;
       bool ok=true;
       rep(i,n/2){
           int x=s[i]-'a',y=s[n-1-i]-'a';
           if(abs(x-y)!=2&&x!=y)ok=false;
       }
       if(ok)printf("YES\n");
       else printf("NO\n");
   }
   return 0;
}