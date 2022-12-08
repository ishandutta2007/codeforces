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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int cnt[5050];
bool ng[5050][5050];
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    rep(i,n){
        cin>>a[i];
        if(++cnt[a[i]]==k+1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    int b[n];
    int used=0;
    rep(i,n){
        if(i<k){
            b[i]=i+1;
            ng[a[i]][i+1]=true;
        }
        else {
            int c=1;
            while(ng[a[i]][c])++c;
            b[i]=c;
            ng[a[i]][c]=true;
        }
    }
    cout<<"YES"<<endl;
    rep(i,n)cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}