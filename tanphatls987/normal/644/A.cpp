#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int main(){
//    freopen("input.inp","r",stdin);
    int n1,n,m;
    cin>>n1>>n>>m;
    if (n1>n*m){
        printf("-1");
        return 0;
    }
    REP(i,0,n){
        if (m%2==0&&i%2){
            FOR(j,1,m){
                int idx=(i+1)*m-j+1;
                printf("%d ",idx>n1?0:idx);
            }
            ENDL;
            continue;
        }
        FOR(j,1,m) {
            int idx=i*m+j;
            printf("%d ",idx>n1?0:idx);
        }
        ENDL;
    }
}