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
   int q;
   cin>>q;
   while(q--){
       int n;
       cin>>n;
       map<int,int> cnt;
       rep(i,n){
           int x;
           scanf("%d",&x);
           ++cnt[x];
       }
       vector<int> ans;
       for(auto x:cnt){
           if(x.second>=2)ans.push_back(x.first);
           if(x.second>=4)ans.push_back(x.first);
       }
       int ans1=1,ans2=50000;
       int m=ans.size();
       rep(i,m-1){
           if(ans[i]*ans2>ans1*ans[i+1]){
               ans1=ans[i];
               ans2=ans[i+1];
           }
       }
       printf("%d %d %d %d\n",ans1,ans1,ans2,ans2);
   }
   return 0;
}