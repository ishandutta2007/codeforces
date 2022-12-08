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
    int t;
    cin>>t;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        n*=3;
        vector<pair<int,int>> v[n];
        rep(i,m){
            int x,y;
            scanf("%d%d",&x,&y);
            --x;--y;
            v[x].emplace_back(i,y);
            v[y].emplace_back(i,x);
        }
        vector<int> ind, mat;
        vector<int> used(n);
        rep(i,n){
            if(used[i])continue;
            used[i]=true;
            bool ok=false;
            for(auto to : v[i]){
                if(!used[to.second]){
                    used[to.second]=true;
                    mat.push_back(to.first);
                    ok=true;
                    break;
                }
            }
            if(!ok)ind.push_back(i);
        }
        if(ind.size()>=n/3){
            printf("IndSet\n");
            rep(i,n/3)printf("%d ",ind[i]+1);
            printf("\n");
        }
        else {
            printf("Matching\n");
            rep(i,n/3)printf("%d ",mat[i]+1);
            printf("\n");
        }
    }
    return 0;
}