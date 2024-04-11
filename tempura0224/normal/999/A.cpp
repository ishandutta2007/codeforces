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
    int n,k;
    cin>>n>>k;
    int left=inf,right=-1;
    rep(i,n){
        int x;
        cin>>x;
        if(x>k){
            left=min(left,i);
            right=max(right,i);
        }
    }
    if(right==-1)cout<<n<<endl;
    else cout<<n-right+left-1<<endl;
    return 0;
}