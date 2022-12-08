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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    int ok=n, ng=(n-1)/2;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        bool can=true;
        for(int i=n-1;i>0;--i){
            if(i-mid>=0&&a[i]<2*a[i-mid])can=false;
        }
        (can?ok:ng)=mid;
    }
    cout<<ok<<endl;
    return 0;
}