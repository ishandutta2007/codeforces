#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

vector<pint> edge;
int n,d,k;
void dfs(int x,int h,int& ma){
    if(h==0)return ;
    rep(i,k-1){
        if(i==0&&x<=d)continue;
        if(edge.size()>=n)return;
        int y=++ma;
        edge.push_back({x,y});
        dfs(y,h-1,ma);
    }
    return;
}

int main(){
    cin>>n>>d>>k;
    n--;
    if(d>n){
        cout<<"NO"<<endl;
        return 0;
    }
    if(n!=1&&k==1){
        cout<<"NO"<<endl;
        return 0;
    }
    rep(i,d)edge.push_back({i+1,i+2});
    int ma=d+1;
    rep(i,d+1)dfs(i+1,min(i,d-i),ma);
    if(edge.size()>=n){
        cout<<"YES"<<endl;
        rep(i,n)printf("%d %d\n",edge[i].first,edge[i].second);
    }
    else cout<<"NO"<<endl;
    return 0;
}