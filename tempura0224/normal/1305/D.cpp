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

vector<int> v[2020];

int d[2020], used[2020];

void dfs(int x,int p){
    for(auto to:v[x]){
        if(to==p||used[to])continue;
        d[to]=d[x]+1;
        dfs(to,x);
    }
}
int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int p;
    while(1){
        int l=0, r=0;
        rep(i,n)d[i]=-1;
        l=p;
        d[l]=0;
        dfs(l,-1);
        int dist = 0;
        rep(i,n){
            if(!used[i] && d[i]>dist){
                dist=d[i];
                r = i;
            }
        }
        if(dist==0)break;
        d[r]=0;
        dfs(r,-1);
        dist = 0;
        rep(i,n){
            if(!used[i] && d[i]>dist){
                dist=d[i];
                l = i;
            }
        }
        cout<<"? "<<l+1<<" "<<r+1<<endl;
        cin>>p;
        --p;
        while(r!=l){
            used[l]=1;
            for(auto to:v[l]){
                if(!used[to]&&d[to]==dist-1){
                    l=to;
                    dist--;
                    break;
                }
            }
        }
        used[r]=1;
        used[p]=false;
    }
    cout<<"! "<<p+1<<endl;
    return 0;
}