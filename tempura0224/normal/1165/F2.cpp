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

vector<int> v[404040];

int main(){
    int n,m;
    cin>>n>>m;
    int sum=0;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    rep(i,m){
        int d,t;
        cin>>d>>t;
        --t;
        v[d].push_back(t);
    }
    int ng=0,ok=2*sum;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        int s=mid;
        vector<int> rem=a;
        int res=sum;
        int ret=0;
        for(int j=mid;j>=0;--j){
            ret+=max(0,s-j);
            s=min(s,j);
            for(auto t : v[j]){
                if(s>0&&rem[t]>0){
                    int get=min(s,rem[t]);
                    rem[t]-=get;
                    s-=get;
                    res-=get;
                }
            }
        }
        if(ret>=2*res)ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
    return 0;
}