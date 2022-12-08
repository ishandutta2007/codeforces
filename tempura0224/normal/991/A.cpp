#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
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
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>d||b>d||a<c||b<c){
        cout<<-1<<endl;
        return 0;
    }
    int ans=d-a-b+c;
    if(ans>0)cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}