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
    int n;
    cin>>n;
    int res=(9*n+1)/2;
    int a[n];
    rep(i,n){
        cin>>a[i];
        res-=a[i];
    }
    if(res<=0){
        cout<<0<<endl;
        return 0;
    }
    sort(a,a+n);
    rep(i,n){
        res-=(5-a[i]);
        if(res<=0){
            cout<<(i+1)<<endl;
            return 0;
        }
    }
    return 0;
}