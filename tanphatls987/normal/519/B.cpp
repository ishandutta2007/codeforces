#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=100;

int n,x,y,z,t;
int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&t);
        x^=t;
    }
    FOR(i,1,n-1){
        scanf("%d",&t);
        y^=t;
    }
    FOR(i,1,n-2){
        scanf("%d",&t);
        z^=t;
    }
    cout<<(x^y)<<'\n'<<(y^z);
}