#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

map<int,int> ma;
int up(int x){
    while (ma[x]){
        ma.erase(x);
        x++;
    }
    ma[x]=1;
    return x;
}
int n,x;
int main(){
    scanf("%d",&n);
    int m=0;
    FOR(i,1,n) {
        scanf("%d",&x);
        m=max(m,up(x));
        //cout<<m;
    }
    cout<<m-(ma.size())+1;
}